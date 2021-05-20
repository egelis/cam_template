#ifndef CAM_TEMPLATE_SAVER_H
#define CAM_TEMPLATE_SAVER_H

#include "../istrategy.h"

class FileSaver {
private:
    ISaveStrategy *m_strategy;
public:
    explicit FileSaver(ISaveStrategy *strategy = nullptr);

    ~FileSaver();

    void setStrategy(ISaveStrategy *strategy);

    void saveFrame(const SyncedFrames &frame);

    void saveFrames(const FramesVector &frames);
};


#endif //CAM_TEMPLATE_SAVER_H
