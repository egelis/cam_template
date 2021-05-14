#include "FileHandler.h"

void FileHandler::saveFrame(const SyncedFrames &frame) {
    size_t nums_of_cameras = frame.size();

    for (size_t cam = 0; cam < nums_of_cameras; cam++)
    {
        std::ofstream outFile("frame" + std::to_string(cam) + ".raw", std::ios::binary);

        auto buffer = frame[cam]->data;
        outFile.write(reinterpret_cast<char *>(buffer.data()),
                      static_cast<std::streamsize>(buffer.size() * sizeof(buffer[0])));

        outFile.close();
    }
}

void FileHandler::saveFrames(const FramesVector &frames) {
    size_t nums_of_frames = frames.size();
    size_t nums_of_cameras = frames[0].size();

    std::vector<std::ofstream> outFiles(nums_of_cameras);
    for (size_t cam = 0; cam < nums_of_cameras; cam++) {
        outFiles[cam].open("frames" + std::to_string(cam) + ".raw", std::ios::binary);
    }

    for (size_t frame = 0; frame < nums_of_frames; frame++)
    {
        for (size_t cam = 0; cam < nums_of_cameras; cam++)
        {
            auto buffer = frames[frame][cam]->data;
            outFiles[cam].write(reinterpret_cast<char *>(buffer.data()),
                                static_cast<std::streamsize>(buffer.size() * sizeof(buffer[0])));
        }
    }

    for (auto &file: outFiles) {
        file.close();
    }
}
