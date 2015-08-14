#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "controller.h"

Controller::Controller(int w, int h) : width(w), height(h){
}

void Controller::addSprite(Sprite& s){
	sprites.push_back(&s);
}

void Controller::render(){
	int i;
	SDL_SetRenderDrawColor( gRenderer, 0xee, 0xee, 0xee, 0xFF );
	SDL_RenderClear( gRenderer );
	if (sprites.size() > 0){
		for(i = 0; i < sprites.size(); i++){
			sprites.at(i)->render(gRenderer);
		}
	}
	//Update screen
	SDL_RenderPresent(gRenderer);
}

bool Controller::init()
{
	if(SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0)
	{
		return false;
	}
	
	SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
	gWindow = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
	if(gWindow == NULL)
	{
		return false;
	}
	
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if( gRenderer == NULL )
	{
		return false;
	}

	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

	return true;
}

void Controller::close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Controller::setWindowMode(int mode){
	if (mode = 1){
		SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN);
	}
}