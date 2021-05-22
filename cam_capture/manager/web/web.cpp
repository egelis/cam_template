#include "web.h"

#include <iostream>

bool WebCamManager::addCamera(std::unique_ptr<ICamera> cam) {
    m_cams.push_back(std::move(cam));

    return true;
}

std::vector<Metadata> WebCamManager::getCamsList() {
    std::vector<Metadata> result;

    for (const auto &c : this->m_cams) {
        result.push_back(c->meta);
    }

    return result;
}

// Проходить в цикле каждую камеру (занося ее в новый поток) и вызывать frames раз getNewFrame

Cams WebCamManager::getFrames(size_t frames) {
    std::vector<std::future<Cam>> futures;
    for (const auto &cam: m_cams) {
        futures.push_back(std::async([&] {
                              Frames res(frames);
                              for (size_t frame = 0; frame < frames; frame++) {
                                  res[frame] = cam->getNewFrame();
                              }
                              return Cam{cam->meta.dev_path, std::move(res)};
                          })
        );
    }

    size_t num_of_cameras = m_cams.size();
    Cams res(num_of_cameras);

    for (size_t cam = 0; cam < num_of_cameras; cam++) {
        res[cam] = futures[cam].get();
    }

    return res;
}

Frame WebCamManager::getFrame() {
    /*std::vector<std::future<Frame>> futures;

    for (const auto &cam: m_cams) {
        futures.push_back(
                std::async([&] {
                    return std::move(cam->getNewFrame());
                })
        );
    }

    const size_t size = this->m_cams.size();
    SyncedFrames res(size);

    for (size_t cam = 0; cam < size; cam++) {
        res[cam] = futures[cam].get();
    }

    return res;*/
    return {};
}

void WebCamManager::initCameras() {
    std::vector<std::future<void>> futures;
    for (const auto &cam: m_cams) {
        futures.push_back(std::async([&] { cam->init(); }));
    }
}
