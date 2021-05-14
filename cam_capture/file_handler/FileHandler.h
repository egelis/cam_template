#ifndef CAM_TEMPLATE_FILEHANDLER_H
#define CAM_TEMPLATE_FILEHANDLER_H

#include "../camera/commons.h"
#include "../manager/commons.h"

#include <fstream>
#include <utility>

class FileHandler {
public:
    FileHandler() = default;

    ~FileHandler() = default;

    /* Saving 1 frame in separate files for each camera */
    static void saveFrame(const SyncedFrames &frame);

    /* Saving frames in separate files for each camera */
    static void saveFrames(const FramesVector &frames);
};


#endif //CAM_TEMPLATE_FILEHANDLER_H
