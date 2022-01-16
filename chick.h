#ifndef Chick_hpp
#define Chick_hpp
#include "gameobject.h"

class Chick : public GameObject
{
public:
    Chick(const char* texturesheet,int x,int y);
    void Update();
    void ced();
    void finish();
private:
    int xpo;
    int ypo;
    int j;
};

#endif

