#ifndef CAM_TEMPLATE_OCOF_SAVE_H
#define CAM_TEMPLATE_OCOF_SAVE_H

#include <fstream>
#include <future>
#include <vector>

#include "../istrategy.h"

class OCOF_Save : public ISaveStrategy {
public:
    ~OCOF_Save() override = default;

    /*Saving frames in separate files for each camera */
    void saveFrames(const Cams &cams, const std::string &path) override;
};


#endif //CAM_TEMPLATE_OCOF_SAVE_H
