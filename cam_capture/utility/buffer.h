#ifndef CAM_BUFFER_H
#define CAM_BUFFER_H

#include <mutex>
#include <vector>


struct CamBuffer{
    std::vector<uint8_t> data;
//    std::mutex lock;
};

#endif // CAM_BUFFER_H
