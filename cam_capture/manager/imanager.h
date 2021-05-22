#ifndef IMANAGER_H
#define IMANAGER_H

#include "../camera/icamera.h"
#include "commons.h"

class ICamManager {
public:
    virtual bool addCamera(std::unique_ptr<ICamera> cam) = 0;

    virtual std::vector<Metadata> getCamsList() = 0;

    virtual void initCameras() = 0;

    virtual Cams getFrames(size_t frames) = 0;

    virtual ~ICamManager() {}
};

#endif // IMANAGER_H
