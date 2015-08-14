#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "sprite.h"
#include "controller.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	// Create and initialize a game controller object.
	// Abort if initialization failed.
	Controller screen(SCREEN_WIDTH, SCREEN_HEIGHT);
	if( !screen.init() )
	{
		cout << "Failed to initialize!" << endl;
		screen.close();
		return 0;
	}

	/** Titlescreen **/
	// [Insert titlescreen code here]

	// Add two sprites to the controller object
	Sprite s1(32,32,64,64);
	screen.addSprite(s1);
	Sprite s2(64,200,128,50);
	screen.addSprite(s2);
	s2.red = 0;

	bool quit = false;
	int frame = 0;
	SDL_Event e;
	while( !quit )
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}
		s1.x ++;
		screen.render();
		if (frame ++ == 60)
		{
			frame = 0;
			s1.x = 0;
		}
	}

	screen.close();
	return 0;
}