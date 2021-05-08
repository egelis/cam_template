cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)

project(cam_template)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "*.h" "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES} )
