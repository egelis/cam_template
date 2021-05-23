#ifndef CAM_TEMPLATE_ISTRATEGY_H
#define CAM_TEMPLATE_ISTRATEGY_H

#include "../commons.h"

class ISaveStrategy {
public:
    virtual ~ISaveStrategy() = default;

    virtual void saveFrames(const Cams &cams, const std::string &path) = 0;
};

#endif //CAM_TEMPLATE_ISTRATEGY_H
