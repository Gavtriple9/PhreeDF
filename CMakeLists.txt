# ############################################################################
# Name:        CMakeLists.txt
# Purpose:     Primary CMake for PhreeDF
# Author:      Gavin Roberts
# Created:     2024-03-15
# Copyright:   (c) 2024 Gavin Roberts
# License:     MIT License
# ############################################################################

cmake_minimum_required(VERSION 3.14...3.22)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # Suppress the warning about writable string literals
  add_compile_options(-Wno-writable-strings)
endif()

# ---- Project ----
project(
  phreedf
  VERSION 0.1.0
  LANGUAGES CXX
)

set(TARGET ${PROJECT_NAME})

# ---- Include guards ----
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(
    FATAL_ERROR
    "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

if(NOT DEFINED BUILD_EXEC)
  set(BUILD_EXEC TRUE)
endif()

# --- Optionally build the project ---
if(BUILD_EXEC)
  # ---- Add dependencies ----
  find_package(wxWidgets REQUIRED)
  find_package(spdlog REQUIRED)

  set(PODOFO_BUILD_LIB_ONLY TRUE CACHE BOOL "" FORCE)
  set(PODOFO_BUILD_STATIC TRUE CACHE BOOL "" FORCE)
  add_subdirectory(${PROJECT_SOURCE_DIR}/lib/podofo)

  # ---- Add source files ----
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

  set(HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf/Core.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf/PhreedfApp.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf/MainFrame.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf/SplitWindow.hpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf/utils/File.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf/utils/ToString.hpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf/debug/DisplayPdfInfo.hpp"
  )

  set(SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/PhreedfApp.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/MainFrame.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/SplitWindow.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/src/utils/File.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/utils/ToString.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/src/debug/DisplayPdfInfo.cpp"
  )

  # --- Add the app icon ---
  if(APPLE)
    set(MACOSX_BUNDLE_ICON_FILE ${PROJECT_SOURCE_DIR}/resources/phreedf)
    set(APP_ICON_MACOSX ${PROJECT_SOURCE_DIR}/resources/phreedf.icns)
    set_source_files_properties(${APP_ICON_MACOSX} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
  endif()

  # ---- Create library ----
  if(APPLE)
    add_executable(${TARGET} MACOSX_BUNDLE ${HEADERS} ${SOURCES} ${APP_ICON_MACOSX})
    set_target_properties(${TARGET} PROPERTIES CXX_STANDARD 17 MACOSX_BUNDLE_INFO_PLIST ${PROJECT_SOURCE_DIR}/resources/Info.plist.in)
  else()
    add_executable(${TARGET} ${HEADERS} ${SOURCES})
    set_target_properties(${TARGET} PROPERTIES CXX_STANDARD 17)
  endif()

  # ----- Add compiler definitions and options ----
  target_compile_definitions(${TARGET} PUBLIC ${wxWidgets_DEFINITIONS})
  target_compile_options(
    ${TARGET}
    PRIVATE
    ${WX_CXX_FLAGS_LIST}
    ${wxWidgets_CXX_FLAGS}
    PUBLIC
    "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->"
  )

  message(STATUS "Podofo_INCLUDE_DIRS: ${Podofo_INCLUDE_DIRS}")

  # ---- Add include directories ----
  target_include_directories(
    ${TARGET}
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${TARGET}-${PROJECT_VERSION}>
    ${wxWidgets_INCLUDE_DIRS}
    ${spdlog_INCLUDE_DIRS}
  )

  message(STATUS "Podofo_LIBRARIES: ${Podofo_LIBRARIES}")

  # ---- Link libraries ----
  target_link_libraries(
    ${TARGET}
    PRIVATE

    # spdlog
    spdlog::spdlog
    $<$<BOOL:${MINGW}>:ws2_32>

    # wxWidgets
    ${wxWidgets_LIBRARIES}

    # podofo
    podofo::podofo
  )
endif()

# ---- Optionally generate documentation ----
if(NOT DEFINED BUILD_DOCS)
  set(BUILD_DOCS FALSE)
endif()

if(BUILD_DOCS)
  find_package(Doxygen REQUIRED)

  if(DOXYGEN_FOUND)
    message(STATUS "Doxygen found")
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_MAN NO)
    set(DOXYGEN_GENERATE_LATEX NO)
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_EXCLUDE_PATTERNS
      "*/lib/*"
      "*/build/*"
    )
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE YES)
    set(DOXYGEN_PROJECT_LOGO "${PROJECT_SOURCE_DIR}/logo.png")
    set(DOXYGEN_HTML_EXTRA_STYLESHEET "${PROJECT_SOURCE_DIR}/docs/doxygen-awesome-css/doxygen-awesome.css")

    doxygen_add_docs(docs ${PROJECT_SOURCE_DIR})
  else()
    message(STATUS "Doxygen not found")
  endif()
endif()

# ---- Optionally generate tests ----
if(NOT DEFINED BUILD_TESTS)
  set(BUILD_TESTS TRUE)
endif()

if(BUILD_TESTS)
  include(tests/CMakeLists.txt)
endif()