#include "web.h"

WebCamera::WebCamera(const Metadata &desc) : m_videoCapture(nullptr) {
    this->meta = desc;

    switch (meta.format) {
        // More formats can be added
        case V4L2_PIX_FMT_YUYV:
            m_buffer_size = meta.height * meta.width * 2;
            break;
        default:
            throw std::runtime_error("Unknown format. Unable to get buffer size.");
    }
}

void WebCamera::init() {
    V4L2DeviceParameters param(meta.dev_path.c_str(), meta.format, meta.width,
                               meta.height, meta.framerate, meta.ioType);

    m_videoCapture = V4l2Capture::create(param);

    warmup();
}

Frame WebCamera::getNewFrame() {
    std::vector<std::byte> buffer(m_buffer_size);
    timeval timeout{10};

    m_videoCapture->isReadable(&timeout);
    m_videoCapture->read(reinterpret_cast<char *>(buffer.data()),
                         buffer.size());

    return std::make_unique<CamBuffer>(CamBuffer{buffer});
}

void WebCamera::warmup() {
    for (auto i = 0; i < 10; i++) {
        getNewFrame();
    }
}
