#############################################################################
# Name:        CMakeLists.txt
# Purpose:     Primary CMake for PhreeDF
# Author:      Gavin Roberts
# Created:     2024-03-15
# Copyright:   (c) 2024 Gavin Roberts
# License:     MIT License
#############################################################################

cmake_minimum_required(VERSION 3.14...3.22)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # Suppress the warning about writable string literals
  add_compile_options(-Wno-writable-strings)
endif()

# ---- Project ----

# Note: update this to your new project's name and version
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

# ---- Add dependencies ----
find_package(wxWidgets REQUIRED)
find_package(Podofo REQUIRED)
find_package(spdlog REQUIRED)

# ---- Add source files ----

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Note: globbing sources is considered bad practice as CMake's generators may not detect new files
# automatically. Keep that in mind when changing files, or explicitly mention them here.
set(HEADERS 
  "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf/Core.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf/PhreedfApp.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/phreedf/MainFrame.h"
)

set(SOURCES 
  "${CMAKE_CURRENT_SOURCE_DIR}/src/PhreedfApp.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/MainFrame.cpp"
)


# --- Add the app icon ---
if (APPLE)
  set(MACOSX_BUNDLE_ICON_FILE ${PROJECT_SOURCE_DIR}/resources/phreedf)
  set(APP_ICON_MACOSX ${PROJECT_SOURCE_DIR}/resources/phreedf.icns) 
  set_source_files_properties(${APP_ICON_MACOSX} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources") 
endif()

# ---- Create library ----

# Note: for header-only libraries change all PUBLIC flags to INTERFACE and create an interface
# add_library(${TARGET} INTERFACE)
if (APPLE)
  add_executable(${TARGET} MACOSX_BUNDLE ${HEADERS} ${SOURCES} ${APP_ICON_MACOSX})
  set_target_properties(${TARGET} PROPERTIES CXX_STANDARD 17 MACOSX_BUNDLE_INFO_PLIST ${PROJECT_SOURCE_DIR}/resources/Info.plist.in)
else()
  add_executable(${TARGET} ${HEADERS} ${SOURCES})
  set_target_properties(${TARGET} PROPERTIES CXX_STANDARD 17)
endif()

target_compile_definitions(${TARGET} PUBLIC ${wxWidgets_DEFINITIONS})

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(
  ${TARGET} 
  PRIVATE 
    ${WX_CXX_FLAGS_LIST} 
    ${wxWidgets_CXX_FLAGS} 
  PUBLIC 
    "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->"
)

# ---- Create source groups for IDEs ----

target_include_directories(
  ${TARGET} 
  PUBLIC  
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${TARGET}-${PROJECT_VERSION}>
    ${wxWidgets_INCLUDE_DIRS}
    ${Podofo_INCLUDE_DIRS}
    ${spdlog_INCLUDE_DIRS}
)

# Link dependencies
target_link_libraries(
  ${TARGET} 
  PRIVATE 
    # spdlog
    spdlog::spdlog 
    $<$<BOOL:${MINGW}>:ws2_32> 

    # podofo
    ${Podofo_LIBRARIES}
  
    # wxWidgets
    ${wxWidgets_LIBRARIES}
)


# ---- Create an installable target ----
# this allows users to install and find the library via `find_package()`.

# the location where the project's version header will be placed should match the project's regular
# header paths
string(TOLOWER ${TARGET}/version.h VERSION_HEADER_LOCATION)


# ---- Generate Documentation ----
find_package(Doxygen REQUIRED dot)

if (DOXYGEN_FOUND)
  message(STATUS "Doxygen found")
  set(DOXYGEN_GENERATE_HTML YES)
  set(DOXYGEN_GENERATE_MAN NO)
  set(DOXYGEN_GENERATE_LATEX NO)
  set(DOXYGEN_RECURSIVE YES)
  set(DOXYGEN_EXCLUDE_PATTERNS 
      "*/lib/*"
      "*/build/*"
      "*/docs/doxygen-awesome-css/*"
  )
  set(USE_MDFILE_AS_MAINPAGE YES)
  set(PROJECT_LOGO "${PROJECT_SOURCE_DIR}/logo.png")
  set(HTML_EXTRA_STYLESHEET "${PROJECT_SOURCE_DIR}/docs/doxygen-awesome-css/doxygen-awesome.css")

  doxygen_add_docs(docs ${PROJECT_SOURCE_DIR})
else()
  message(STATUS "Doxygen not found")
endif()