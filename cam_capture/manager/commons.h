#ifndef MANAGER_COMMONS_H
#define MANAGER_COMMONS_H

#include <vector>
#include "../camera/commons.h"

typedef std::vector<Frame>                  Frames;
typedef std::pair<std::string, Frames>      Cam;    // name of camera and its frames
typedef std::vector<Cam>                    Cams;

#endif // MANAGER_COMMONS_H
