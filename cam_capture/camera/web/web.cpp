#include "web.h"

WebCamera::WebCamera(const Metadata &desc) : videoCapture(nullptr) {
    this->meta = desc;

    switch (meta.format) {
        // Can add more formats
        case V4L2_PIX_FMT_YUYV:
            buffer_size = meta.height * meta.width * 2;
            break;
        default:
            throw std::runtime_error("Unknown format. Unable to get buffer size.");
    }
}

void WebCamera::init() {
    V4L2DeviceParameters param(meta.dev_path.c_str(), meta.format, meta.width,
                               meta.height, meta.framerate, meta.ioType);

    videoCapture = V4l2Capture::create(param);
}

Frame WebCamera::getNewFrame() {
    std::vector<std::byte> buffer(buffer_size);
    timeval timeout{100};

    videoCapture->isReadable(&timeout);
    videoCapture->read(reinterpret_cast<char *>(buffer.data()),
                       buffer.size());

    return std::make_unique<CamBuffer>(CamBuffer{buffer});
}
