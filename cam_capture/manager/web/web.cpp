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

FramesVector WebCamManager::getFrames(size_t frames) {
    FramesVector res(frames);

    for (size_t frame = 0; frame < frames; frame++) {
        res[frame] = getFrame();
    }

    return res;
}

SyncedFrames WebCamManager::getFrame() {
    std::vector<std::future<Frame>> futures;

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

    return res;
}

void WebCamManager::initCameras(State state) {
    if (state == State::ASYNC) {
        std::vector<std::future<void>> futures;
        for (const auto &cam: m_cams)
            futures.push_back(std::async([&] { cam->init(); }));
    }
    else {
        for (const auto &cam: m_cams)
            cam->init();
    }
}
