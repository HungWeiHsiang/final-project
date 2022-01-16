#include "ghost.h"

Ghost::Ghost(const char* texturesheet,int x,int y):GameObject(texturesheet, x, y){}

void Ghost::Update()
{
    //when gameover,put the crabs out of the window
    if(gover==1)
    {
        xpos=800;
        ypos=800;
    }
    //
    cntt=cntt+1;
    if(cntt>=1000&&gover==0)
    {
        
        lvl1[3][11]=1;
        lvl1[3][13]=1;
        lvl1[16][11]=1;
        lvl1[16][13]=1;
    }
    int t=xpos;
    int r=ypos;
    star=star+1;
    //every object is stationary when the gane starts(let player knows the NPCs' position when the game starts)
    if(star>400)
    {
    //
        //let crabs move after the walls are break
        while(cntt>=1000&&gover==0&&t==xpos&&r==ypos)
        {
        //
            //when the crab is too close to player,let it decelerate
            if(xpos-px>=-128&&ypos-py>=-128&&xpos-px<=128&&ypos-py<=128)
            {
                int tt=rand()%10+3;
                int dn=tt%4;
                switch(dn)
                {
                case 0:
                    if(i!=2&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
                    {
                        xpos=xpos+4;
                        i=0;
                        break;
                    }
                case 1:
                    if(i!=3&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
                    {
                        ypos=ypos+4;
                        i=1;
                        break;
                    }
                case 2:
                    if(i!=0&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
                    {
                        xpos=xpos-4;
                        i=2;
                        break;
                    }
                case 3:
                    if(i!=1&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
                    {
                        ypos=ypos-4;
                        i=3;
                        break;
                    }
                default:
                    {
                        break;
                    }
                }
            }
            //
            //when the crab isn't too close to player,let it move randomly
            else
            {
                //because the crabs will accelerate,we need to ajdust their posotion to avoid them can't turn
                if(xpos%32==4)
                {
                    xpos=xpos-4;
                }
                if(xpos%32==28)
                {
                    xpos=xpos+4;
                }
                if(ypos%32==4)
                {
                    ypos=ypos-4;
                }
                if(ypos%32==28)
                {
                    ypos=ypos+4;
                }
                if(xpos%32==24)
                {
                    xpos=xpos+8;
                }
                if(xpos%32==8)
                {
                    xpos=xpos-8;
                }
                if(ypos%32==24)
                {
                    ypos=ypos+8;
                }
                if(ypos%32==8)
                {
                    ypos=ypos-8;
                }
                if(xpos%32==12)
                {
                    xpos=xpos-12;
                }
                if(xpos%32==20)
                {
                    xpos=xpos+12;
                }
                if(ypos%32==12)
                {
                    ypos=ypos-12;
                }
                if(ypos%32==20)
                {
                    ypos=ypos+12;
                }
                //
                int tt=rand()%10+3;
                int dn=tt%4;
                switch(dn)
                {
                case 0:
                    if(i!=2&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
                    {
                        xpos=xpos+16;
                        i=0;
                        break;
                    }
                case 1:
                    if(i!=3&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
                    {
                        ypos=ypos+16;
                        i=1;
                        break;
                    }
                case 2:
                    if(i!=0&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
                    {
                        xpos=xpos-16;
                        i=2;
                        break;
                    }
                case 3:
                    if(i!=1&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
                    {
                        ypos=ypos-16;
                        i=3;
                        break;
                    }
                default:
                    {
                        break;
                    }
                }
            }
            //
        }
    }
    gx=xpos;
    gy=ypos;
    srcRect.h=32;
    srcRect.w=32;
    srcRect.x=0;
    srcRect.y=0;
    
    destRect.x=xpos;
    destRect.y=ypos;
    destRect.w=srcRect.w;
    destRect.h=srcRect.h;
    //judge whether player is too close to the crabs
    if(t<800)
    {
        dead();
    }
    //
}


