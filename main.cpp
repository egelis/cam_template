#include <iostream>

#include "cam_capture/manager/web/web.h"
#include "cam_capture/camera/fake/fake.h"
#include "cam_capture/camera/web/web.h"
#include "cam_capture/file_handler/FileHandler.h"

#include "profile.h"

using namespace std;

int main() {
    WebCamManager manager;
    {
        LOG_DURATION("video2 initialization")
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
    }

    {
        LOG_DURATION("video0 initialization")
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

    {
        LOG_DURATION("getFrame and saveFrame")
        auto frame = manager.getFrame();
        FileHandler::saveFrame(frame);
    }

    {
        LOG_DURATION("getFrames(300) and saveFrames");
        auto frames = manager.getFrames(300);
        FileHandler::saveFrames(frames);
    }

    return 0;
}
