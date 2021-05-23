#include "saver.h"

FileSaver::FileSaver(std::unique_ptr<ISaveStrategy> strategy) : m_strategy(std::move(strategy)) {

}

void FileSaver::setStrategy(std::unique_ptr<ISaveStrategy> strategy) {
    m_strategy = std::move(strategy);
}

void FileSaver::saveFrames(const Cams &cams, const std::string &path) {
    return m_strategy->saveFrames(cams, path);
}
