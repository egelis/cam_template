cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 20)

project(cam_template)

SET(SOURCES main.cpp
        cam_capture/camera/fake/fake.cpp
        cam_capture/camera/web/web.cpp
        cam_capture/manager/web/web.cpp
        cam_capture/utility/buffer.cpp
        cam_capture/file_saver/saver.cpp
        cam_capture/file_saver/strategies/oneCamOneFile/OCOF_Save.cpp
        cam_capture/file_saver/strategies/oneCamManyFiles/OCMF_Save.cpp)

SET(HEADERS cam_capture/camera/fake/fake.h
        cam_capture/camera/web/web.h
        cam_capture/camera/commons.h
        cam_capture/camera/icamera.h
        cam_capture/manager/commons.h
        cam_capture/manager/imanager.h
        cam_capture/manager/web/web.h
        cam_capture/utility/buffer.h
        cam_capture/file_saver/strategies/istrategy.h
        cam_capture/file_saver/saver.h
        cam_capture/file_saver/commons.h
        cam_capture/file_saver/strategies/oneCamOneFile/OCOF_Save.h
        cam_capture/file_saver/strategies/oneCamManyFiles/OCMF_Save.h
        profile.h)

include_directories("${CMAKE_SOURCE_DIR}/3rd_party/libv4l2cpp/inc")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/3rd_party/libv4l2cpp/libv4l2wrapper.a
        pthread)
