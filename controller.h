#ifndef __controller
#define __controller
	#include "sprite.h"
	class Controller {
	public:
		Controller(int w, int h);
		bool init();
		void close();
		void render();
		void addSprite(Sprite& s);
		void setWindowMode(int mode);
	private:
		std::vector<Sprite*> sprites;
		int width;
		int height;
		SDL_Window* gWindow = NULL;
		SDL_Renderer* gRenderer = NULL;
	};
#endif
