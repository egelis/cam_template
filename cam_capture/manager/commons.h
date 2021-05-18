#ifndef MANAGER_COMMONS_H
#define MANAGER_COMMONS_H

#include <vector>
#include "../camera/commons.h"

enum class State {
    SYNC,
    ASYNC
};

typedef std::vector<Frame>            SyncedFrames;
typedef std::vector<SyncedFrames>     FramesVector;

#endif // MANAGER_COMMONS_H
