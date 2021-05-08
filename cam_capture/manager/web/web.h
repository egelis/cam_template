#ifndef WEB_MANAGER_H
#define WEB_MANAGER_H

#include "../imanager.h"
#include "../../camera/icamera.h"

class WebCamManager : public ICamManager {
public:
    bool addCamera(std::unique_ptr<ICamera> cam) override;

    std::vector<Metadata> getCamsList() override;

    FramesVector getFrames(size_t frames) override;
    CamsVector getFrame() override;

    ~WebCamManager() override {}

private:
    std::vector<std::unique_ptr<ICamera>> cams;
};

#endif // WEB_MANAGER_H
