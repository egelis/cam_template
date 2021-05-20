#include "saver.h"

FileSaver::FileSaver(ISaveStrategy *strategy) : m_strategy(strategy) {

}

void FileSaver::setStrategy(ISaveStrategy *strategy) {
    delete m_strategy;
    m_strategy = strategy;
}

void FileSaver::saveFrame(const SyncedFrames &frame) {
    m_strategy->saveFrame(frame);
}

void FileSaver::saveFrames(const FramesVector &frames) {
    m_strategy->saveFrames(frames);
}

FileSaver::~FileSaver() {
    delete m_strategy;
}
