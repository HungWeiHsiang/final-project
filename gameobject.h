#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "texturemanager.h"
#include "map.h"
using namespace std;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern int gx;
extern int gy;
extern int px;
extern int py;
extern int cx;
extern int cy;
extern int gover;
extern int fin;
extern int cch;
extern int tes;
extern int ugl;
extern int star;
extern int cntt;
extern int s;
extern int v;
extern int u;
extern int uup;
extern int ddo;
extern int lle;
extern int rri;
extern int cup;
extern int cdo;
extern int cle;
extern int cri;
extern int nup;
extern int ndo;
extern int nle;
extern int nri;
extern int kee;
extern int acc;
extern int lvl1[20][25];

int ggov();
int finn();

class GameObject
{
public:
	GameObject(const char* texturesheet,int x,int y);
    GameObject();
	virtual void Update();
	void Render();
	void dead();
	void gameover();
protected:
	int xpos;
	int ypos;
	int i;
	int sto;
	int stoo;
	int det;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};


