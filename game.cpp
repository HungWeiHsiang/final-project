#include "game.h"

Cloud* ghost1;
Cloud* ghost2;
Cloud* ghost3;
Cloud* ghost4;
Ghost* ghost5;
Ghost* ghost6;
Chick* chi1;
Chick* chi2;
Chick* chi3;
Chick* chi4;
Player* p1;
Map* map;

Game::Game():ruu(false){}
Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
    IMG_Quit();
} 

void Game::init(const char *title,int xpos,int ypos,int width,int height,bool fullscreen)
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
    }
    else
    {
        window = SDL_CreateWindow( title, xpos, ypos, width, height, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
        }
        else
        {
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( renderer == NULL )
            {
                cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
            }
            else
            {
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
                }
                ruu = true;
            }
        }
    }
    //creat object and map
	ghost1=new Cloud("clouddd.bmp",96,96);
	ghost2=new Cloud("clouddd.bmp",672,512);
	ghost3=new Cloud("clouddd.bmp",672,96);
	ghost4=new Cloud("clouddd.bmp",96,512);
	ghost5=new Ghost("crabb.bmp",384,96);
	ghost6=new Ghost("crabb.bmp",384,512);
	chi1=new Chick("chickenn.bmp",96,288);
	chi2=new Chick("chickenn.bmp",672,320);
	chi3=new Chick("chickenn.bmp",384,32);
	chi4=new Chick("chickenn.bmp",384,576);
	p1=new Player("baby.png",384,304);
	map=new Map();
}

void Game::handleEvents()
{
	//update the player's position
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 )
    {
        if (e.type == SDL_QUIT)
            ruu = false;
        p1->handleEvent( e );
        if(ggov())
		{
			map->DrawMap();
			break;
		}
    }	
}
//update map and object
void Game::update()
{
	map->upd();
	p1->Update();
	ghost1->Update();
	ghost2->Update();
	ghost3->Update();
	ghost4->Update();
	ghost5->Update();
	ghost6->Update();
	chi1->Update();
	chi2->Update();
	chi3->Update();
	chi4->Update();	
}
//
void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	chi1->Render();
	chi2->Render();
	chi3->Render();
	chi4->Render();
	ghost1->Render();
	ghost2->Render();
	ghost3->Render();
	ghost4->Render();
	ghost5->Render();
	ghost6->Render();
	p1->Render();
	SDL_RenderPresent(renderer);
}
// 
bool Game::running()
{
	return ruu;
}

