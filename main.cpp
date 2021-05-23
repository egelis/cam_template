#include <iostream>

#include "cam_capture/manager/web/web.h"
#include "cam_capture/camera/fake/fake.h"
#include "cam_capture/camera/web/web.h"

#include "cam_capture/file_saver/saver.h"
#include "cam_capture/file_saver/strategies/oneCamOneFile/OCOF_Save.h"
#include "cam_capture/file_saver/strategies/oneCamManyFiles//OCMF_Save.h"

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

    auto cams_list = manager.getCamsList();
    std::cout << "\n\nList of cameras:" << std::endl;
    for (const auto &c : cams_list) {
        std::cout << "Metadata. dev_path: '" << c.dev_path << "', additional: '"
                  << c.additional << "'" << std::endl;
    }

    Cams cams;
    {
        LOG_DURATION("getFrames(300)");
        cams = manager.getFrames(300);
    }

    {
        LOG_DURATION("saveFrames(300) OCOF");
        FileSaver saver(make_unique<OCOF_Save>());
        saver.saveFrames(cams, "Frames/OCOF/");
    }

    {
        LOG_DURATION("saveFrames(300) OCMF");
        FileSaver saver(make_unique<OCMF_Save>());
        saver.saveFrames(cams, "Frames/OCMF/");
    }

    return 0;
}
