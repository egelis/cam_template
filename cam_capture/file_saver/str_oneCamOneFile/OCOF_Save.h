#ifndef CAM_TEMPLATE_OCOF_SAVE_H
#define CAM_TEMPLATE_OCOF_SAVE_H

#include <fstream>

#include "../istrategy.h"

class OCOF_Save : public ISaveStrategy {
    ~OCOF_Save() override = default;

    /* Saving 1 frame in separate files for each camera */
    void saveFrame(const SyncedFrames &frame) override;

    /* Saving frames in separate files for each camera */
    void saveFrames(const FramesVector &frames) override;
};


#endif //CAM_TEMPLATE_OCOF_SAVE_H
