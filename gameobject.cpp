#include "gameobject.h"

// judge whether the game is finished(successed or failed)
int ggov()
{
	if(gover!=1)
	{
		return 0;	
	}
	uup=0;
	ddo=0;
	lle=0;
	rri=0;
	return 1;
}
//
// judge whether the game is successed 
int finn()
{
	if(fin!=1)
	{
		return 0;	
	}
	return 1;
}
//
GameObject::GameObject(const char* texturesheet,int x,int y)
{
	objTexture=TextureManager::LoadTexture(texturesheet);
	xpos=x;
	ypos=y;
}
GameObject::GameObject(){}
void GameObject::Update()
{
}
//judge whether player is catched by the cloud
void GameObject::dead()
{
	if((gx-px<24&&px-gx<24&&gy==py)||(gy-py<24&&py-gy<24&&px==gx)||(gx-px<12&&px-gx<12&&gy-py<12&&py-gy<12))
	{
		gameover();
	}
}
//
//judge gameover
void GameObject::gameover()
{
	gover=1;
}
//
void GameObject::Render()
{
	SDL_RenderCopy(renderer,objTexture,&srcRect,&destRect);
}

