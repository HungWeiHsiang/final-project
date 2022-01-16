#include "player.h"

Player::Player(const char* texturesheet,int x,int y):GameObject()
{
    objTexture=TextureManager::LoadTexture(texturesheet);
    xpo = x;
    ypo = y;
    dir = -1;
}

void Player::handleEvent( SDL_Event& e )
{
    //let player can move
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:
            uup = 1;
            nup = 1;
            break;
        case SDLK_DOWN:
            ddo = 1;
            ndo = 1;
            break;
        case SDLK_LEFT:
            lle = 1;
            nle = 1;
            break;
        case SDLK_RIGHT:
            rri = 1;
            nri = 1;
            break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:
            uup = 0;
            nup = 0;
            cup=0;
            break;
        case SDLK_DOWN:
            ddo = 0;
            ndo = 0;
            cdo=0;
            break;
        case SDLK_LEFT:
            lle = 0;
            nle = 0;
            cle=0;
            break;
        case SDLK_RIGHT:
            rri = 0;
            nri = 0;
            cri=0;
            break;
        }
    }
    //
}
void Player::Update()
{
    //when gameover,put the player out of the window
    if(gover==1)
    {
        xpo=800;
        ypo=800;
    }
    //
    //compute how long the butter is pressed(right:cri,down:cdo,left:cle,up:cup)
    if(uup == 1)
    cup=cup+1;
    if(ddo == 1)
    cdo=cdo+1;
    if(lle == 1)
    cle=cle+1;
    if(rri == 1)
    cri=cri+1;
    //
    if(cntt>=1000&&gover==0)
    {
        lvl1[3][11]=1;
        lvl1[3][13]=1;
        lvl1[16][11]=1;
        lvl1[16][13]=1;
    }
    int xyx=xpo;
    int yxy=ypo;
    star=star+1;
    //let player can move earlier than NPC
    if(star>300)
    {
    //
        //if player press more than three bottom,let the bottom pressed earliest null
        if(cup!=0&&cdo!=0&&cri!=0)
        {
            if(cup>=cdo&&cup>cri)
            {
                cup=0;
                uup=0;
            }
            if(cdo>=cri&&cdo>cup)
            {
                cdo=0;
                ddo=0;
            }
            if(cri>=cup&&cri>cdo)
            {
                cri=0;
                rri=0;
            }
        }
        if(cup!=0&&cdo!=0&&cle!=0)
        {
            if(cup>=cdo&&cup>cle)
            {
                cup=0;
                uup=0;
            }
            if(cdo>=cle&&cdo>cup)
            {
                cdo=0;
                ddo=0;
            }
            if(cle>=cup&&cle>cdo)
            {
                cle=0;
                lle=0;
            }
        }
        if(cle!=0&&cdo!=0&&cri!=0)
        {
            if(cle>=cdo&&cle>cri)
            {
                cle=0;
                lle=0;
            }
            if(cdo>=cri&&cdo>cle)
            {
                cdo=0;
                ddo=0;
            }
            if(cri>=cle&&cri>cdo)
            {
                cri=0;
                rri=0;
            }
        }
        if(cup!=0&&cri!=0&&cle!=0)
        {
            if(cup>=cri&&cup>cle)
            {
                cup=0;
                uup=0;
            }
            if(cri>=cle&&cri>cup)
            {
                cri=0;
                rri=0;
            }
            if(cle>=cup&&cle>cri)
            {
                cle=0;
                lle=0;
            }
        }
        //
        //if player press up and down or right and left bottom at the same time,let the bottom pressed earlier null
        if((cup!=0&&cdo!=0)||(cri!=0&&cle!=0))
        {
            if(cup>cdo)
            {
                cup=0;
                uup=0;
            }
            else if(cup<=cdo)
            {
                cdo=0;
                ddo=0;
            }
            if(cle>=cri)
            {
                cle=0;
                lle=0;
            }
            else if(cle<cri)
            {
                cri=0;
                rri=0;
            }
        }
        //
        //if player press two bottom,execute the bottom pressed later in advance.if the bottom pressed later is null(the player will bump into wall),execute the bottom pressed earlier.
        //player can turn before and after the intersection if he is colse to the intersection
        else if(cri!=0&&cdo!=0)
        {
            if(cri>cdo)
            {
                if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
                (lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                {
                    if(xpo%32==4)
                    {
                        xpo=xpo-4;
                    }
                    if(xpo%32==28)
                    {
                        xpo=xpo+4;
                    }
                    ypo=ypo+u;
                    dir=1;
                }
                else if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
                (lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                {
                    if(ypo%32==4)
                    {
                        ypo=ypo-4;
                    }
                    if(ypo%32==28)
                    {
                        ypo=ypo+4;
                    }
                    xpo=xpo+u;
                    dir=0;
                }
            }
            else if(cri<=cdo)
            {
                if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
                (lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                {
                    if(ypo%32==4)
                    {
                        ypo=ypo-4;
                    }
                    if(ypo%32==28)
                    {
                        ypo=ypo+4;
                    }
                    xpo=xpo+u;
                    dir=0;
                }
                else if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
                (lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                {
                    if(xpo%32==4)
                    {
                        xpo=xpo-4;
                    }
                    if(xpo%32==28)
                    {
                        xpo=xpo+4;
                    }
                    ypo=ypo+u;
                    dir=1;
                }
            }
        }
        else if(cri!=0&&cup!=0)
        {
            if(cri>cup)
            {
                if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
                (lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                {
                    if(xpo%32==4)
                    {
                        xpo=xpo-4;
                    }
                    if(xpo%32==28)
                    {
                        xpo=xpo+4;
                    }
                    ypo=ypo-u;
                    dir=3;
                }
                else if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
                (lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                {
                    if(ypo%32==4)
                    {
                        ypo=ypo-4;
                    }
                    if(ypo%32==28)
                    {
                        ypo=ypo+4;
                    }
                    xpo=xpo+u;
                    dir=0;
                }
            }
            else if(cri<=cup)
            {
                if((lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
                (lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                {
                    if(ypo%32==4)
                    {
                        ypo=ypo-4;
                    }
                    if(ypo%32==28)
                    {
                        ypo=ypo+4;
                    }
                    xpo=xpo+u;
                    dir=0;
                }
                else if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
                (lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                {
                    if(xpo%32==4)
                    {
                        xpo=xpo-4;
                    }
                    if(xpo%32==28)
                    {
                        xpo=xpo+4;
                    }
                    ypo=ypo-u;
                    dir=3;
                }
            }
        }
        else if(cle!=0&&cup!=0)
        {
            if(cle<=cup)
            {
                if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
                ||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                {
                    if(ypo%32==4)
                    {
                        ypo=ypo-4;
                    }
                    if(ypo%32==28)
                    {
                        ypo=ypo+4;
                    }
                    xpo=xpo-u;
                    dir=2;
                }
                else if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
                (lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                {
                    if(xpo%32==4)
                    {
                        xpo=xpo-4;
                    }
                    if(xpo%32==28)
                    {
                        xpo=xpo+4;
                    }
                    ypo=ypo-u;
                    dir=3;
                }
            }
            else if(cle>cup)
            {
                if((lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
                (lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                {
                    if(xpo%32==4)
                    {
                        xpo=xpo-4;
                    }
                    if(xpo%32==28)
                    {
                        xpo=xpo+4;
                    }
                    ypo=ypo-u;
                    dir=3;
                }
                else if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
                ||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                {
                    if(ypo%32==4)
                    {
                        ypo=ypo-4;
                    }
                    if(ypo%32==28)
                    {
                        ypo=ypo+4;
                    }
                    xpo=xpo-u;
                    dir=2;
                }
            }
        }
        else if(cle!=0&&cdo!=0)
        {
            if(cle<=cdo)
            {
                if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
                ||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                {
                    if(ypo%32==4)
                    {
                        ypo=ypo-4;
                    }
                    if(ypo%32==28)
                    {
                        ypo=ypo+4;
                    }
                    xpo=xpo-u;
                    dir=2;
                }
                else if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
                (lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                {
                    if(xpo%32==4)
                    {
                        xpo=xpo-4;
                    }
                    if(xpo%32==28)
                    {
                        xpo=xpo+4;
                    }
                    ypo=ypo+u;
                    dir=1;
                }
            }
            else if(cle>cdo)
            {
                if((lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
                (lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                {
                    if(xpo%32==4)
                    {
                        xpo=xpo-4;
                    }
                    if(xpo%32==28)
                    {
                        xpo=xpo+4;
                    }
                    ypo=ypo+u;
                    dir=1;
                }
                else if((lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
                ||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                {
                    if(ypo%32==4)
                    {
                        ypo=ypo-4;
                    }
                    if(ypo%32==28)
                    {
                        ypo=ypo+4;
                    }
                    xpo=xpo-u;
                    dir=2;
                }
            }
        }
        //
        //
        else if(ggov()!=1)
        {
            //if player press one bottom,judge if the direction is efficient(the player will not bump into wall)
            //player can turn before and after the intersection if he is colse to the intersection
            if(((nri==1&&nle!=1)||cri!=0)&&(lvl1[ypo/32][xpo/32+1]!=0||(lvl1[(ypo+4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0)||
            (lvl1[(ypo-4)/32][xpo/32+1]!=0&&lvl1[(ypo)/32][xpo/32+1]==0))&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
            {
                if(ypo%32==4)
                {
                    ypo=ypo-4;
                }
                if(ypo%32==28)
                {
                    ypo=ypo+4;
                }
                xpo=xpo+u;
                dir=0;
            }
            else if(((ndo==1&&nup!=1)||cdo!=0)&&(lvl1[ypo/32+1][xpo/32]!=0||(lvl1[ypo/32+1][(xpo+4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0)||
            (lvl1[ypo/32+1][(xpo-4)/32]!=0&&lvl1[ypo/32+1][(xpo)/32]==0))&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
            {
                if(xpo%32==4)
                {
                    xpo=xpo-4;
                }
                if(xpo%32==28)
                {
                    xpo=xpo+4;
                }
                ypo=ypo+u;
                dir=1;
            }
            else if(((nle==1&&nri!=1)||cle!=0)&&(lvl1[ypo/32][(xpo-1)/32]!=0||(lvl1[(ypo+4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0)
            ||(lvl1[(ypo-4)/32][(xpo-1)/32]!=0&&lvl1[(ypo)/32][(xpo-1)/32]==0))&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
            {
                if(ypo%32==4)
                {
                    ypo=ypo-4;
                }
                if(ypo%32==28)
                {
                    ypo=ypo+4;
                }
                xpo=xpo-u;
                dir=2;
            }
            else if(((nup==1&&ndo!=1)||cup!=0)&&(lvl1[(ypo-1)/32][xpo/32]!=0||(lvl1[(ypo-1)/32][(xpo+4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0)||
            (lvl1[(ypo-1)/32][(xpo-4)/32]!=0&&lvl1[(ypo-1)/32][(xpo)/32]==0))&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
            {
                if(xpo%32==4)
                {
                    xpo=xpo-4;
                }
                if(xpo%32==28)
                {
                    xpo=xpo+4;
                }
                ypo=ypo-u;
                dir=3;
            }
            //
            //
        }
        //if player didn,t press any bottom or all bottom pressed is null(will bump into wall},people will move along his original direction for some distance
        if(xyx==xpo&&yxy==ypo)
        {
            if(ggov()!=1)
            {
                if(kee==0)
                {
                    kee=5;
                }
                else if(xpo%32==0&&ypo%32==0&&kee>2)
                {
                    kee=kee-1;
                }
                if(kee>3)
                {
                    if(dir==0&&lvl1[ypo/32][xpo/32+1]!=0&&lvl1[(ypo+31)/32][xpo/32+1]!=0)
                    {
                        xpo=xpo+u;
                        dir=0;
                    }
                    else if(dir==1&&lvl1[ypo/32+1][xpo/32]!=0&&lvl1[ypo/32+1][(xpo+31)/32]!=0)
                    {
                        ypo=ypo+u;
                        dir=1;
                    }
                    else if(dir==2&&lvl1[ypo/32][(xpo-1)/32]!=0&&lvl1[(ypo+31)/32][(xpo-1)/32]!=0)
                    {
                        xpo=xpo-u;
                        dir=2;
                    }
                    else if(dir==3&&lvl1[(ypo-1)/32][xpo/32]!=0&&lvl1[(ypo-1)/32][(xpo+31)/32]!=0)
                    {
                        ypo=ypo-u;
                        dir=3;
                    }
                }
            }
        }
        if(uup==1||ddo==1||rri==1||lle==1)
        {
            kee=0;
        }
        //
        if(xyx!=xpo||yxy!=ypo)
        {
			//change the picture
		    if (frame/4 == 0)
		    {
		        switch (dir)
		        {
		            case 3: // up
		                srcRect.x = 0;
		                srcRect.y = 96;
		                break;
		            case 1: // down
		                srcRect.x = 0;
		                srcRect.y = 0;
		                break;
		            case 2: //left
		                srcRect.x = 0;
		                srcRect.y = 32;
		                break;
		            case 0: // right
		                srcRect.x = 0;
		                srcRect.y = 64;
		                break;
		            default:
		            	srcRect.x = 0;
		                srcRect.y = 96;
		        }
		    }
		    if (frame/2 == 1)
		    {
		        switch (dir)
		        {
		            case 3: // up
		                srcRect.x = 32;
		                srcRect.y = 96;
		                break;
		            case 1: // down
		                srcRect.x = 32;
		                srcRect.y = 0;
		                break;
		            case 2: //left
		                srcRect.x = 32;
		                srcRect.y = 32;
		                break;
		            case 0: // right
		                srcRect.x = 32;
		                srcRect.y = 64;
		                break;
		            default:
		            	srcRect.x = 32;
		                srcRect.y = 96;
		        }
		    }
		    if (frame/4 == 2)
		    {
		        switch (dir)
		        {
		            case 3: // up
		                srcRect.x = 64;
		                srcRect.y = 96;
		                break;
		            case 1: // down
		                srcRect.x = 64;
		                srcRect.y = 0;
		                break;
		            case 2: //left
		                srcRect.x = 64;
		                srcRect.y = 32;
		                break;
		            case 0: // right
		                srcRect.x = 64;
		                srcRect.y = 64;
		                break;
		            default:
		            	srcRect.x = 64;
		                srcRect.y = 96;
		        }
		    }
		    //    	
		}
    }
    if(dir==-1)
    {
    	srcRect.x = 0;
		srcRect.y = 96;
	}
    px=xpo;
    py=ypo;
    
    
    srcRect.w = 32;
    srcRect.h = 32;
    
    destRect.x=xpo;
    destRect.y=ypo;
    destRect.w=srcRect.w;
    destRect.h=srcRect.h;
    
}

