#ifndef ghost_hpp
#define ghost_hpp
#include "gameobject.h"

class Ghost : public GameObject
{
public:
    Ghost(const char* texturesheet,int x,int y);
    void Update();
};

#endif

