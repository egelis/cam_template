#ifndef CAM_BUFFER_H
#define CAM_BUFFER_H

#include <mutex>
#include <vector>


struct CamBuffer{
    std::vector<std::byte> data;
//    std::mutex lock;
};

#endif // CAM_BUFFER_H
