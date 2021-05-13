#ifndef ICAMERA_H
#define ICAMERA_H

#include <string>
#include "commons.h"

#include <V4l2Device.h>
#include <V4l2Capture.h>

struct Metadata {
    std::string dev_path;
    size_t width;
    size_t height;
    unsigned int format;
    int framerate;
    V4l2IoType ioType = IOTYPE_MMAP;

    std::string additional;
};

struct ICamera {
    virtual Frame getNewFrame() = 0;

    virtual ~ICamera() = default;

    Metadata meta;
};

#endif // ICAMERA_H
