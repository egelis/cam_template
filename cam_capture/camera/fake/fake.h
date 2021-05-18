#ifndef FAKE_CAMERA_H
#define FAKE_CAMERA_H

#include "../icamera.h"

class FakeCamera : public ICamera {
public:
    explicit FakeCamera(const Metadata &desc);

    Frame getNewFrame() override;

    void init() override;

    ~FakeCamera() override = default;
};

#endif // FAKE_CAMERA_H
