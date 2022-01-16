#ifndef cloud_h
#define cloud_h

#include "gameobject.h"

class Cloud : public GameObject
{
public:
    Cloud(const char* texturesheet,int x,int y);
    void Update();
};

#endif

