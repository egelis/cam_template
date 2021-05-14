#include <iostream>

#include "cam_capture/manager/web/web.h"
#include "cam_capture/camera/fake/fake.h"
#include "cam_capture/camera/web/web.h"

#include <fstream>

using namespace std;

void saveToFile(const string &file_name, Frame frame) {
    ofstream outFile(file_name, ios::binary | ios::app);

    auto buffer{frame->data};
    outFile.write(reinterpret_cast<char *>(buffer.data()),
                  buffer.size() * sizeof(buffer[0]));

    outFile.close();
}

int main() {
    WebCamManager manager;
    {
        Metadata meta;
        meta.dev_path = "/dev/video0";
        meta.width = 640;
        meta.height = 480;
        meta.format = V4L2_PIX_FMT_YUYV;
        meta.framerate = 30;
        meta.additional = "Integrated camera";

        manager.addCamera(std::make_unique<WebCamera>(meta));
    }

    {
        Metadata meta;
        meta.dev_path = "/dev/video2";
        meta.width = 640;
        meta.height = 480;
        meta.format = V4L2_PIX_FMT_YUYV;
        meta.framerate = 30;
        meta.additional = "Web camera";

        manager.addCamera(std::make_unique<WebCamera>(meta));
    }

    /*{
        Metadata meta;
        meta.width = 640;
        meta.height = 480;
        meta.additional = "fake cam 2";
        manager.addCamera(std::make_unique<FakeCamera>(meta));
    }*/

    auto cams = manager.getCamsList();
    std::cout << "\n\nList of cameras:" << std::endl;
    for (const auto &c : cams) {
        std::cout << "Metadata. dev_path: '" << c.dev_path << "', additional: '"
                  << c.additional << "'" << std::endl;
    }

    /*auto frame = manager.getFrame();
    for (size_t cam = 0; cam < cams.size(); cam++) {
        saveToFile("camera" + to_string(cam) + ".raw", move(frame[cam]));
    }*/

    auto frames = manager.getFrames(300);

    for (auto &frame : frames) {
        for (size_t cam = 0; cam < cams.size(); cam++) {
            saveToFile("camera" + to_string(cam) + ".raw", move(frame[cam]));
        }
    }

    return 0;
}
