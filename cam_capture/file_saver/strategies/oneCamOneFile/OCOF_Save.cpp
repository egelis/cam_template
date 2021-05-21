#include "OCOF_Save.h"

#define WRITE_TO_FILE(cam, outFile)                                                   \
    auto buffer = (cam)->data;                                                        \
    (outFile).write(reinterpret_cast<char *>(buffer.data()),                          \
                  static_cast<std::streamsize>(buffer.size() * sizeof(buffer[0])));   \


void OCOF_Save::saveFrame(const SyncedFrames &frame) {
    size_t nums_of_cameras = frame.size();

    // Open files
    std::vector<std::ofstream> outFiles(nums_of_cameras);
    for (size_t num = 0; num < nums_of_cameras; num++) {
        outFiles[num].open("frame" + std::to_string(num) + ".raw", std::ios::binary);
    }

    // Write
    int num = 0;
    for (const auto &cam: frame) {
        WRITE_TO_FILE(cam, outFiles[num++]);
    }

    // Close
    for (auto &file: outFiles) {
        file.close();
    }
}

void OCOF_Save::saveFrames(const FramesVector &frames) {
    size_t nums_of_cameras = frames[0].size();

    std::vector<std::ofstream> outFiles(nums_of_cameras);
    for (size_t num = 0; num < nums_of_cameras; num++) {
        outFiles[num].open("frames" + std::to_string(num) + ".raw", std::ios::binary);
    }

    for (const auto &frame: frames) {
        int num = 0;
        for (const auto &cam: frame) {
            WRITE_TO_FILE(cam, outFiles[num++]);
        }
    }

    for (auto &file: outFiles) {
        file.close();
    }
}
