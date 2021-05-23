#ifndef CAM_TEMPLATE_SAVER_H
#define CAM_TEMPLATE_SAVER_H

#include <memory>

#include "strategies/istrategy.h"

class FileSaver {
private:
    std::unique_ptr<ISaveStrategy> m_strategy;
public:
    explicit FileSaver(std::unique_ptr<ISaveStrategy> strategy = nullptr);

    ~FileSaver() = default;

    void setStrategy(std::unique_ptr<ISaveStrategy> strategy);

    void saveFrames(const Cams &cams, const std::string &path);
};


#endif //CAM_TEMPLATE_SAVER_H
