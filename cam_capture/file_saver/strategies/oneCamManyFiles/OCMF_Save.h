#ifndef CAM_TEMPLATE_OCMF_SAVE_H
#define CAM_TEMPLATE_OCMF_SAVE_H

#include <filesystem>
#include <fstream>
#include <future>
#include <vector>

#include "../istrategy.h"

class OCMF_Save : public ISaveStrategy {
public:
    ~OCMF_Save() override = default;

    /*Saving 1 frame in 1 file for each camera */
    void saveFrames(const Cams &cams, const std::string &path) override;
};


#endif //CAM_TEMPLATE_OCMF_SAVE_H
