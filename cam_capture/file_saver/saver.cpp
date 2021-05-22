#include "saver.h"

FileSaver::FileSaver(std::unique_ptr<ISaveStrategy> strategy) : m_strategy(std::move(strategy)) {

}

void FileSaver::setStrategy(std::unique_ptr<ISaveStrategy> strategy) {
    m_strategy = std::move(strategy);
}

/*void FileSaver::saveFrame(const SyncedFrames &frame) {
    m_strategy->saveFrame(frame);
}

void FileSaver::saveFrames(const FramesVector &frames) {
    m_strategy->saveFrames(frames);
}*/
