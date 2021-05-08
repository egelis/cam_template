#ifndef WEB_CAMERA_H
#define WEB_CAMERA_H

#include "../icamera.h"

class WebCamera : public ICamera{
public:
    WebCamera(Metadata descr);
    Frame getNewFrame() override;
    ~WebCamera(){};
};

#endif // WEB_CAMERA_H
