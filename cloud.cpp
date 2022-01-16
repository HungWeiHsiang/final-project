#include "cloud.h"

Cloud::Cloud(const char* texturesheet,int x,int y):GameObject(texturesheet, x, y){}

void Cloud::Update()
{
    //when gameover,put the clouds out of the window
    if(gover==1)
    {
        xpos=800;
        ypos=800;
    }
    //
    if(!gover)
    {
        if(ugl==2&&xpos%32==0&&ypos%32==0&&cntt>=800)
        {
            cout<<"Warning:red clouds become very very fast!!"<<endl;
            acc=4;
            ugl=3;
        }
        else if(ugl==1&&xpos%32==0&&ypos%32==0&&cntt>=400)
        {
            cout<<"Warning:red clouds become more faster!!"<<endl;
            acc=2;
            ugl=2;
        }
    }
    int t=xpos;
    int r=ypos;
    star=star+1;
    //every object is stationary when the game starts(let player knows the NPCs' position when the game starts)
    if(star>400)
    {
    //
    //let clouds can chase player
    if(cntt>=1000)
    {
        if(xpos==px&&ypos-py<=96&&ypos>py)
        {
            if(lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
            {
                ypos=ypos-s*acc;
                i=3;
            }
            else if(lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
            {
                xpos=xpos+s*acc;
                i=0;
            }
            else if(lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
            {
                xpos=xpos-s*acc;
                i=2;
            }
        }
        else if(ypos==py&&xpos-px<=96&&xpos>px)
        {
            if(lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
            {
                xpos=xpos-s*acc;
                i=2;
            }
            else if(lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
            {
                ypos=ypos-s*acc;
                i=3;
            }
            else if(lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
            {
                ypos=ypos+s*acc;
                i=1;
            }
        }
        else if(xpos==px&&py-ypos<=96&&ypos<py)
        {
            if(lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
            {
                ypos=ypos+s*acc;
                i=1;
            }
            else if(lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
            {
                xpos=xpos+s*acc;
                i=0;
            }
            else if(lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
            {
                xpos=xpos-s*acc;
                i=2;
            }
        }
        else if(ypos==py&&px-xpos<=96&&xpos<px)
        {
            if(lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
            {
                xpos=xpos+s*acc;
                i=0;
            }
            else if(lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
            {
                ypos=ypos-s*acc;
                i=3;
            }
            else if(lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
            {
                ypos=ypos+s*acc;
                i=1;
            }
        }
        else if(xpos-px<=48&&xpos>px&&ypos-py<=48&&ypos>py)
        {
            if(xpos-px>=ypos-py&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
            {
                ypos=ypos-s*acc;
                i=3;
            }
            if(xpos-px<ypos-py&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
            {
                xpos=xpos-s*acc;
                i=2;
            }
        }
        else if(px-xpos<=48&&xpos<px&&ypos-py<=48&&ypos>py)
        {
            if(px-xpos>=ypos-py&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
            {
                ypos=ypos-s*acc;
                i=3;
            }
            if(px-xpos<ypos-py&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
            {
                xpos=xpos+s*acc;
                i=0;
            }
        }
        else if(px-xpos<=48&&xpos<px&&py-ypos<=48&&ypos<py)
        {
            if(px-xpos>=py-ypos&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
            {
                ypos=ypos+s*acc;
                i=1;
            }
            if(px-xpos<py-ypos&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
            {
                xpos=xpos+s*acc;
                i=0;
            }
        }
        else if(xpos-px<=48&&xpos>px&&py-ypos<=48&&ypos<py)
        {
            if(xpos-px>=py-ypos&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
            {
                ypos=ypos+s*acc;
                i=1;
            }
            if(xpos-px>=py-ypos&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
            {
                xpos=xpos-s*acc;
                i=2;
            }
        }
    }
    //
    //if clouds didn't chase the player,let it move randomly
    //we judge if the move is efficient(ie didn't bump into wall),ex.lvl1[ypos/32][xpos/32+1]!=0,lvl1[(ypos+31)/32][xpos/32+1]!=0
    //to avoid the cloud moving forward and backward repeatly,we let the clouds will not move the opposite side to it's bofore move,ex.i!=2(i=0:right,i=1:down'i=2:left,i=3:up)
    if(t==xpos&&r==ypos)
    {
        while(gover==0&&t==xpos&&r==ypos)
        {
            int tt=rand()%10+3;
            int dn=tt%4;
            switch(dn)
            {
            case 0:
                if(i!=2&&lvl1[ypos/32][xpos/32+1]!=0&&lvl1[(ypos+31)/32][xpos/32+1]!=0)
                {
                    xpos=xpos+s*acc;
                    i=0;
                    break;
                }
            case 1:
                if(i!=3&&lvl1[ypos/32+1][xpos/32]!=0&&lvl1[ypos/32+1][(xpos+31)/32]!=0)
                {
                    ypos=ypos+s*acc;
                    i=1;
                    break;
                }
            case 2:
                if(i!=0&&lvl1[ypos/32][(xpos-1)/32]!=0&&lvl1[(ypos+31)/32][(xpos-1)/32]!=0)
                {
                    xpos=xpos-s*acc;
                    i=2;
                    break;
                }
            case 3:
                if(i!=1&&lvl1[(ypos-1)/32][xpos/32]!=0&&lvl1[(ypos-1)/32][(xpos+31)/32]!=0)
                {
                    ypos=ypos-s*acc;
                    i=3;
                    break;
                }
            default:
                {
                    break;
                }
            }
        }
    }
    //
    //
    //
    //because the coulds will accelerate,we need to ajdust their posotion to avoid them can't turn
    if(acc==4&&xpos%4==2)
    {
        if(xpos%32==2)
        {
            xpos=xpos-2;
        }
        if(xpos%32==30)
        {
            xpos=xpos+2;
        }
    }
    if(acc==4&&ypos%4==2)
    {
        if(ypos%32==2)
        {
            ypos=ypos-2;
        }
        if(ypos%32==30)
        {
            ypos=ypos+2;
        }
    }
    if(acc==2&&xpos%2==1)
    {
        if(xpos%32==1)
        {
            xpos=xpos-1;
        }
        if(xpos%32==31)
        {
            xpos=xpos+1;
        }
    }
    if(acc==2&&ypos%2==1)
    {
        if(ypos%32==1)
        {
            ypos=ypos-1;
        }
        if(ypos%32==31)
        {
            ypos=ypos+1;
        }
    }
    //
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
    //judge whether player is catched by the cloud
    if(t<800)
    {
        dead();
    }
    //
}

