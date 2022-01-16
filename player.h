#ifndef player_hpp
#define player_hpp
#include "gameobject.h"

extern int frame;

class Player : public GameObject
{
public:
    Player(const char* texturesheet,int x,int y);
    void Update();
    void handleEvent( SDL_Event& e );
private:
    int xpo;
    int ypo;
    int j;
    int dir;
};

#endif

