#include "OCOF_Save.h"

#define WRITE_TO_FILE(frame, outFile)                                                 \
    auto buffer = (frame)->data;                                                      \
    (outFile).write(reinterpret_cast<char *>(buffer.data()),                          \
                  static_cast<std::streamsize>(buffer.size() * sizeof(buffer[0])));   \


using namespace std;

void OCOF_Save::saveFrames(const Cams &cams, const string &path) {
    vector<future<void>> futures;

    for (const auto &cam: cams) {
        futures.push_back(async([&] {
                              ofstream outFile(path + cam.first + ".raw", ios::binary);

                              for (const auto &frame: cam.second) {
                                  WRITE_TO_FILE(frame, outFile);
                              }

                              outFile.close();
                          })
        );
    }
}
