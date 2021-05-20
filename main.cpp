#include <iostream>

#include "cam_capture/manager/web/web.h"
#include "cam_capture/camera/fake/fake.h"
#include "cam_capture/camera/web/web.h"

#include "cam_capture/file_saver/saver/saver.h"
#include "cam_capture/file_saver/str_oneCamOneFile/OCOF_Save.h"

#include "profile.h"

using namespace std;

int main() {
    WebCamManager manager;
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

    /*{
        Metadata meta;
        meta.width = 640;
        meta.height = 480;
        meta.additional = "fake cam 2";
        manager.addCamera(std::make_unique<FakeCamera>(meta));
    }*/

    {
        LOG_DURATION("Cameras initialization");
        manager.initCameras();
    }

    auto cams = manager.getCamsList();
    std::cout << "\n\nList of cameras:" << std::endl;
    for (const auto &c : cams) {
        std::cout << "Metadata. dev_path: '" << c.dev_path << "', additional: '"
                  << c.additional << "'" << std::endl;
    }

    {
        LOG_DURATION("getFrame")
        auto frame = manager.getFrame();

        {
            LOG_DURATION("saveFrame")
            FileSaver saver(new OCOF_Save);
            saver.saveFrame(frame);
        }
    }

    {
        LOG_DURATION("getFrames(300)");
        auto frames = manager.getFrames(300);

        {
            LOG_DURATION("saveFrames(300)");
            FileSaver saver(new OCOF_Save);
            saver.saveFrames(frames);
        }
    }

    return 0;
}
