#include "web.h"

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
    std::vector<std::future<Frame>> futures;

    for (const auto &cam: cams) {
        futures.push_back(
                std::async([&] {
                    return std::move(cam->getNewFrame());
                })
        );
    }

    const size_t size = this->cams.size();
    SyncedFrames res(size);

    for (size_t cam = 0; cam < size; cam++) {
        res[cam] = futures[cam].get();
    }

    // One thread
    /*const size_t size = this->cams.size();
    SyncedFrames res(size);

    for (size_t cam = 0; cam < size; cam++) {
        std::chrono::time_point<std::chrono::system_clock> now =
                std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        std::cout << cams[cam]->meta.additional << ": "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "\n";

        res[cam] = std::move(cams[cam]->getNewFrame());
    }*/

    return res;
}
