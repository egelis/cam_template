#include "web.h"

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

Cams WebCamManager::getFrames(size_t frames) {
    Cams res(m_cams.size());

    // allocate memory and set name of camera
    for (int num = 0; auto &r : res) {
        r.first = m_cams[num++]->meta.dev_path;
        r.second.resize(frames);
    }

    // for each frame
    for (size_t frame = 0; frame < frames; frame++) {
        // create vector of features (1 future - 1 camera)
        std::vector<std::future<Frame>> futures;

        // start threads of getting frames from all cameras
        for (const auto &cam : m_cams) {
            futures.push_back(std::async([&] { return std::move(cam->getNewFrame()); }));
        }

        // get feature results
        for (size_t cam = 0; cam < m_cams.size(); cam++) {
            res[cam].second[frame] = futures[cam].get();
        }
    }

    return res;
}

void WebCamManager::initCameras() {
    std::vector<std::future<void>> futures;
    for (const auto &cam: m_cams) {
        futures.push_back(std::async([&] { cam->init(); }));
    }
}
