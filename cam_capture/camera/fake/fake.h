#ifndef FAKE_CAMERA_H
#define FAKE_CAMERA_H

#include "../icamera.h"

class FakeCamera : public ICamera{
public:
    FakeCamera(Metadata descr);
    Frame getNewFrame() override;

    ~FakeCamera(){};
};

#endif // FAKE_CAMERA_H
