#ifndef CAM_TEMPLATE_ISTRATEGY_H
#define CAM_TEMPLATE_ISTRATEGY_H

#include "../commons.h"

class ISaveStrategy {
public:
    virtual ~ISaveStrategy() = default;

    virtual void saveFrame(const SyncedFrames &frame) = 0;

    virtual void saveFrames(const FramesVector &frames) = 0;
};

#endif //CAM_TEMPLATE_ISTRATEGY_H
