cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)

project(cam_template)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "*.h" "*.cpp")

include_directories("3rd_party/libv4l2cpp/inc")

add_executable(${PROJECT_NAME} ${SOURCE_FILES} )

target_link_libraries(${PROJECT_NAME} 3rd_party/libv4l2cpp/libv4l2wrapper.a
        pthread)
