cmake_minimum_required(VERSION 3.10)

project(WastelandEscaper VERSION 1.0)

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
