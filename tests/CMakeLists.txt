enable_testing()
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(TEST_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/tests) # Change this to your desired directory

add_executable(example ${PROJECT_SOURCE_DIR}/tests/src/test_example.cpp)
target_compile_definitions(example PRIVATE BOOST_TEST_DYN_LINK)

target_include_directories(
  example 
  PRIVATE 
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(
  example 
  PRIVATE 
    ${Boost_LIBRARIES}
)

set_target_properties(example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${TEST_BINARY_DIR}
)

add_test(NAME example COMMAND example)
set_tests_properties(example PROPERTIES TIMEOUT 10)