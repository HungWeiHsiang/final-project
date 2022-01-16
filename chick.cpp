#include "chick.h"

Chick::Chick(const char* texturesheet,int x,int y):GameObject()
{
    objTexture=TextureManager::LoadTexture(texturesheet);
    xpo=x;
    ypo=y;
}
void Chick::Update()
{
    //when gameover,put the chickens out of the window
    if(gover==1&&ypo<640)
    {
        xpo=800;
        ypo=800;
    }
    //
    int t=xpo;
    int r=ypo;
    star=star+1;
    //every object is stationary when the game starts(let player knows the NPCs' position when the game starts)
    if(star>400)
    {
    //
        // jugde if the chicken is catched
        if(r<640)
        {
        //
            //let the chicken move faster at the beginning when player is too close to it
            //let the chicken escape when player is too close to it
            if(det<16)
            {
                if(xpo==px&&ypo-py<=96&&ypo>py)
                {
                    if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+u;
                        j=1;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+u;
                        j=0;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-u;
                        j=2;
                        det=det+1;
                    }
                }
                else if(ypo==py&&xpo-px<=96&&xpo>px)
                {
                    if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+u;
                        j=0;
                        det=det+1;
                    }
                    else if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-u;
                        j=3;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+u;
                        j=1;
                        det=det+1;
                    }
                }
                else if(xpo==px&&py-ypo<=96&&ypo<py)
                {
                    if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-u;
                        j=3;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+u;
                        j=0;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-u;
                        j=2;
                        det=det+1;
                    }
                }
                else if(ypo==py&&px-xpo<=96&&xpo<px)
                {
                    if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-u;
                        j=2;
                        det=det+1;
                    }
                    else if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-u;
                        j=3;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+u;
                        j=1;
                        det=det+1;
                    }
                }
                else if(xpo-px<=48&&xpo>px&&ypo-py<=48&&ypo>py)
                {
                    if(xpo-px<=ypo-py&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+u;
                        j=1;
                        det=det+1;
                    }
                    if(xpo-px>ypo-py&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+u;
                        j=0;
                        det=det+1;
                    }
                }
                else if(px-xpo<=48&&xpo<px&&ypo-py<=48&&ypo>py)
                {
                    if(px-xpo<=ypo-py&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+u;
                        j=1;
                        det=det+1;
                    }
                    if(px-xpo>ypo-py&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-u;
                        j=2;
                        det=det+1;
                    }
                }
                else if(px-xpo<=48&&xpo<px&&py-ypo<=48&&ypo<py)
                {
                    if(px-xpo<=py-ypo&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-u;
                        j=3;
                        det=det+1;
                    }
                    if(px-xpo>py-ypo&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-u;
                        j=2;
                        det=det+1;
                    }
                }
                else if(xpo-px<=48&&xpo>px&&py-ypo<=48&&ypo<py)
                {
                    if(xpo-px<=py-ypo&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-u;
                        j=3;
                        det=det+1;
                    }
                    if(xpo-px>py-ypo&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+u;
                        j=0;
                        det=det+1;
                    }
                }
                //because the chickens will accelerate,we need to ajdust their posotion to avoid them can't turn
                if(det>0)
                {
                    if(xpo%32==2)
                    {
                        xpo=xpo-2;
                    }
                    if(xpo%32==30)
                    {
                        xpo=xpo+2;
                    }
                    if(ypo%32==2)
                    {
                        ypo=ypo-2;
                    }
                    if(ypo%32==30)
                    {
                        ypo=ypo+2;
                    }
                }
                //
            }
            //
            //
            //if the player is continuous too close to it,retuen to it's original speed
            //let the chicken escape when player is too close to it
            if(det>=16)
            {
                if(xpo==px&&ypo-py<=96&&ypo>py)
                {
                    if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+v;
                        j=1;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+v;
                        j=0;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-v;
                        j=2;
                        det=det+1;
                    }
                }
                else if(ypo==py&&xpo-px<=96&&xpo>px)
                {
                    if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+v;
                        j=0;
                        det=det+1;
                    }
                    else if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-v;
                        j=3;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+v;
                        j=1;
                        det=det+1;
                    }
                }
                else if(xpo==px&&py-ypo<=96&&ypo<py)
                {
                    if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-v;
                        j=3;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+v;
                        j=0;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-v;
                        j=2;
                        det=det+1;
                    }
                }
                else if(ypo==py&&px-xpo<=96&&xpo<px)
                {
                    if(lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-v;
                        j=2;
                        det=det+1;
                    }
                    else if(lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-v;
                        j=3;
                        det=det+1;
                    }
                    else if(lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+v;
                        j=1;
                        det=det+1;
                    }
                }
                else if(xpo-px<=48&&xpo>px&&ypo-py<=48&&ypo>py)
                {
                    if(px-xpo>=py-ypo&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+v;
                        j=1;
                        det=det+1;
                    }
                    if(px-xpo<py-ypo&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+v;
                        j=0;
                        det=det+1;
                    }
                }
                else if(px-xpo<=48&&xpo<px&&ypo-py<=48&&ypo>py)
                {
                    if(xpo-px>=py-ypo&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+v;
                        j=1;
                        det=det+1;
                    }
                    if(xpo-px>=py-ypo&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-v;
                        j=2;
                        det=det+1;
                    }
                }
                else if(px-xpo<=48&&xpo<px&&py-ypo<=48&&ypo<py)
                {
                    if(xpo-px>=ypo-py&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-v;
                        j=3;
                        det=det+1;
                    }
                    if(xpo-px<ypo-py&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-v;
                        j=2;
                        det=det+1;
                    }
                }
                else if(xpo-px<=48&&xpo>px&&py-ypo<=48&&ypo<py)
                {
                    if(px-xpo>=ypo-py&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-v;
                        j=3;
                        det=det+1;
                    }
                    if(px-xpo<ypo-py&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+v;
                        j=0;
                        det=det+1;
                    }
                }
            }
            //
            //
            //when player isn't too close to it,let it move randomly
            //if player is too close to it but it can't escape
            while(gover==0&&r<640&&t==xpo&&r==ypo)
            {
                det=0;
                int tt=rand()%10+3;
                int dn=tt%4;
                switch(dn)
                {
                case 0:
                    if(j!=2&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+v;
                        j=0;
                        break;
                    }
                case 1:
                    if(j!=3&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+v;
                        j=1;
                        break;
                    }
                case 2:
                    if(j!=0&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-v;
                        j=2;
                        break;
                    }
                case 3:
                    if(j!=1&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-v;
                        j=3;
                        break;
                    }
                default:
                    {
                        break;
                    }
                }
            }
            //
            //
        }
    }
    cx=xpo;
    cy=ypo;
    srcRect.h=32;
    srcRect.w=32;
    srcRect.x=0;
    srcRect.y=0;
    
    destRect.x=xpo;
    destRect.y=ypo;
    destRect.w=srcRect.w;
    destRect.h=srcRect.h;
    //judge whether chichen is catched
    if(r<640)
    {
        ced();
    }
    //
}
//judge whether chichen is catched
void Chick::ced()
{
    if((cx-px<16&&px-cx<16&&cy==py)||(cy-py<16&&py-cy<16&&cx==px)||(cy-py<8&&py-cy<8&&cx-px<8&&px-cx<8))
    {
        xpo=0+32*cch;
        ypo=640;
        cch=cch+1;
        //judge whether all chichen is catched
        if(cch==4)
        {
            finish();
        }
        //
    }
}
//
//judge success
void Chick::finish()
{
    gover=1;
    fin=1;
}
//


