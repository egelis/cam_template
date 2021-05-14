#include "web.h"
#include <algorithm>
#include <iostream>

bool WebCamManager::addCamera(std::unique_ptr<ICamera> cam) {
    cams.push_back(std::move(cam));

    return true;
}

std::vector<Metadata> WebCamManager::getCamsList() {
    std::vector<Metadata> result;

    for (const auto &c : this->cams) {
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
    const size_t size = this->cams.size();
    SyncedFrames res(size);

    for (size_t cam = 0; cam < size; cam++) {
        res[cam] = std::move(cams[cam]->getNewFrame());
    }

    return res;
}
