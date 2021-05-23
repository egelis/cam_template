#include "OCOF_Save.h"

void OCOF_Save::saveFrames(const Cams &cams, const std::string &path) {
    std::vector<std::future<void>> futures;

    for (const auto &cam: cams) {
        futures.push_back(std::async([&] {
                              std::ofstream outFile(path + cam.first + ".raw", std::ios::binary);

                              for (const auto &frame: cam.second) {
                                  auto buffer = frame->data;
                                  outFile.write(reinterpret_cast<char *>(buffer.data()),
                                                static_cast<std::streamsize>(buffer.size() * sizeof(buffer[0])));
                              }

                              outFile.close();
                          })
        );
    }
}
