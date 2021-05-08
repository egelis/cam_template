#include "web.h"
#include <algorithm>
#include <iostream>

bool WebCamManager::addCamera(std::unique_ptr<ICamera> cam)
{
    cams.push_back(std::move(cam));
    // TODO: finish ?
    return true;
}

std::vector<Metadata> WebCamManager::getCamsList()
{
    std::vector<Metadata> result;
    for (const auto& c : this->cams) {
        result.push_back(c->meta);
    }
    return result;
}

FramesVector WebCamManager::getFrames(size_t frames)
{
    const size_t size = this->cams.size();

    FramesVector res(size);

    for (size_t frame = 0; frame < frames; frame++){
        for (size_t cam = 0; cam < size; cam++){
            // TODO: finish
        }
    }
    return res;
}

CamsVector WebCamManager::getFrame()
{
    const size_t size = this->cams.size();

    CamsVector res(size);

    for (size_t cam = 0; cam < size; cam++){
        // TODO: finish
    }
    return res;
}
