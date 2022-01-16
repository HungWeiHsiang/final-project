#include "game.h"

int gx;
int gy;
int px;
int py;
int cx;
int cy;
int gover=0;
int fin=0;
int cch=0;
int tes=0;
int ugl=1;
int star=300;
int cntt=0;
int s=1;
int v=2;
int u=4;
int uup=0;
int ddo=0;
int lle=0;
int rri=0;
int cup;
int cdo;
int cle;
int cri;
int nup;
int ndo;
int nle;
int nri;
int kee=0;
int acc=1;
int frame = 0;

SDL_Window *window;
SDL_Renderer* renderer;
Game *game;
//initialize,upload and end the game
int main(int argc,char *argv[])
{
    const int fps=8;
    const int fdelay=320/fps;
    Uint32 fstart;
    int ftime;
    game=new Game();
    game->init("Running Chick",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,672,false);
    //let the game update
    while(game->running())
    {
        
        fstart=SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        ftime=SDL_GetTicks()-fstart;
        if(fdelay>ftime)
        {
            SDL_Delay(fdelay-ftime);
        }
        ++frame;
        if (frame/4 > 2)
            frame = 0;
    }
    return 0;
}
//

