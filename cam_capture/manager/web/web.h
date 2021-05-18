#ifndef WEB_MANAGER_H
#define WEB_MANAGER_H

#include "../imanager.h"
#include "../../camera/icamera.h"

#include <future>
#include <vector>

class WebCamManager : public ICamManager {
public:
    bool addCamera(std::unique_ptr<ICamera> cam) override;

    std::vector<Metadata> getCamsList() override;

    void initCameras(State state = State::ASYNC) override;

    FramesVector getFrames(size_t frames) override;

    SyncedFrames getFrame() override;

    ~WebCamManager() override = default;

private:
    std::vector<std::unique_ptr<ICamera>> cams;
};

#endif // WEB_MANAGER_H
