cmake_minimum_required(VERSION 3.14...3.22)

project(PhreedfExamples LANGUAGES CXX)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage(
  GITHUB_REPOSITORY jarro2783/cxxopts
  VERSION 3.0.0
  OPTIONS "CXXOPTS_BUILD_EXAMPLES NO" "CXXOPTS_BUILD_TESTS NO" "CXXOPTS_ENABLE_INSTALL YES"
)

CPMAddPackage(NAME Phreedf SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

# ---- Create standalone executable ----

set(SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 OUTPUT_NAME Phreedf)

target_link_libraries(${PROJECT_NAME} Phreedf::Phreedf cxxopts)
