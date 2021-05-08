#ifndef ICAMERA_H
#define ICAMERA_H

#include <string>
#include "commons.h"

struct Metadata{
    std::string dev_path;
    size_t width;
    size_t height;

    // TODO: add fields

    std::string additional;
};

struct ICamera {
    virtual Frame getNewFrame() = 0;
    virtual ~ICamera(){};

    Metadata meta;
};

#endif // ICAMERA_H
