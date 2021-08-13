#include "OCMF_Save.h"

using namespace std;

#define WRITE_TO_FILE(frame, outFile)                                                 \
    auto buffer = (frame)->data;                                                      \
    (outFile).write(reinterpret_cast<char *>(buffer.data()),                          \
                  static_cast<streamsize>(buffer.size() * sizeof(buffer[0])));        \


void OCMF_Save::saveFrames(const Cams &cams, const string &path) {
    vector<future<void>> futures;

    for (const auto &cam: cams) {
        filesystem::create_directory(path + cam.first);

        futures.push_back(async([&] {
                              for (int num = 1; const auto &frame: cam.second) {
                                  ofstream outFile(path + "/" + cam.first + "/" + to_string(num++)
                                                   + ".raw", ios::binary);

                                  WRITE_TO_FILE(frame, outFile);

                                  outFile.close();
                              }
                          })
        );
    }
}
