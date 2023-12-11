cmake_minimum_required(VERSION 3.10)

project(WastelandEscaper VERSION 2.0)

configure_file(main.h.in main.h)

add_library(WastelandNavigator wasteland_navigator.cpp)
target_include_directories(WastelandNavigator PUBLIC
    ${PROJECT_SOURCE_DIR}
)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
)
target_link_libraries(${PROJECT_NAME} PUBLIC
    WastelandNavigator
)

enable_testing()

add_test(NAME Example1 COMMAND ${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/input_example_1.txt)
set_tests_properties(Example1
    PROPERTIES PASS_REGULAR_EXPRESSION "Steps required to escape wasteland: 2"
)

add_test(NAME Example2 COMMAND ${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/input_example_2.txt)
set_tests_properties(Example2
    PROPERTIES PASS_REGULAR_EXPRESSION "Steps required to escape wasteland: 6"
)
