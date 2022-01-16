#pragma once
#include "texturemanager.h"
#include "map.h"
#include "ghost.h"
#include "chick.h"
#include "player.h"
#include "cloud.h"

class Game
{
public:
	Game();
	~Game();
	void init(const char* title,int xpos,int ypos,
	int width,int height,bool fullscreen);
	void handleEvents();
	void update();
	void render();
	bool running();
private:
    bool ruu;
};

