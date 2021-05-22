#include <iostream>

#include "cam_capture/manager/web/web.h"
#include "cam_capture/camera/fake/fake.h"
#include "cam_capture/camera/web/web.h"

#include "cam_capture/file_saver/saver.h"
#include "cam_capture/file_saver/strategies/oneCamOneFile/OCOF_Save.h"

#include "profile.h"

#include <fstream>

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

    /*{
        LOG_DURATION("getFrame")
        auto frame = manager.getFrame();

        {
            LOG_DURATION("saveFrame")
            FileSaver saver(make_unique<OCOF_Save>());
            saver.saveFrame(frame);
        }
    }*/

    {
        LOG_DURATION("getFrames(300)");
        auto cameras = manager.getFrames(300);

        std::vector<std::ofstream> outFiles(cams.size());
        for (size_t num = 0; num < cams.size(); num++) {
            outFiles[num].open("frames" + std::to_string(num) + ".raw", std::ios::binary);
        }

        for (const auto &[name, frames]: cameras) {
            static int num = 0;
            for (const auto &frame: frames) {
                auto buffer = frame->data;
                outFiles[num].write(reinterpret_cast<char *>(buffer.data()),
                                      static_cast<std::streamsize>(buffer.size() * sizeof(buffer[0])));
            }
            num++;
        }

        for (auto &file: outFiles) {
            file.close();
        }

        /*{
            LOG_DURATION("saveFrames(300)");
            FileSaver saver(make_unique<OCOF_Save>());
            saver.saveFrames(frames);
        }*/
    }

    return 0;
}
