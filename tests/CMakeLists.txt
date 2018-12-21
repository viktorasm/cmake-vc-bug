cmake_minimum_required(VERSION 2.6)
project(tests)

enable_testing()

add_subdirectory (lib/googletest-master/googletest)
include_directories(lib/googletest-master/googletest/include)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} gtest)

add_test(
    NAME "tests"
    COMMAND tests
)

set_tests_properties(tests PROPERTIES
	ENVIRONMENT "LD_LIBRARY_PATH=my-custom-library-path"
)

