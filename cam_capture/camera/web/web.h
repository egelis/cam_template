#ifndef WEB_CAMERA_H
#define WEB_CAMERA_H

#include "../icamera.h"

#include<vector>
#include <memory>

class WebCamera : public ICamera {
private:
    V4l2Capture *m_videoCapture;
    size_t m_buffer_size;
public:
    explicit WebCamera(const Metadata &desc);

    Frame getNewFrame() override;

    void init() override;

    ~WebCamera() override = default;
};

#endif // WEB_CAMERA_H
