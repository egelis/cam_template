#include <iostream>

#include "cam_capture/manager/web/web.h"
#include "cam_capture/camera/fake/fake.h"
#include "cam_capture/camera/web/web.h"

#include <fstream>

using namespace std;

int main()
{
//    WebCamManager manager;
    {
        Metadata meta;
        meta.dev_path = "/dev/video2";
        meta.width = 640;
        meta.height = 480;
        meta.format = V4L2_PIX_FMT_YUYV;
        meta.framerate = 30;
        meta.additional = "cam 1";

        WebCamera w(meta);

//        auto frame = w.getNewFrame()->data;
//        ofstream outFile;
//        outFile.open("video1.raw", ios::binary);
//        outFile.write(reinterpret_cast<char*>(frame.data()), frame.size() * sizeof(frame[0]));
//        outFile.close();

//        manager.addCamera(std::make_unique<WebCamera>(meta));
    }

    /*{
        Metadata meta;
        meta.width = 640;
        meta.height = 480;
        meta.additional = "fake cam 2";
        manager.addCamera(std::make_unique<FakeCamera>(meta));
    }*/

//    auto cams = manager.getCamsList();
//
//    std::cout << "List of cameras:" << std::endl;
//
//    for (const auto& c : cams){
//        std::cout << "Metadata. dev_path: '" << c.dev_path << "', additional: '" << c.additional << "'" << std::endl;
//    }
//
//    auto frame = manager.getFrame();
//    auto frames = manager.getFrames(30);

    // TODO: saveToFile(frames)

    return 0;
}
