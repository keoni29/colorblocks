#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.h"

Sprite::Sprite(int x, int y, int w, int h):x(x),y(y),w(w),h(h){
	tex = NULL;
	rect = {x, y, w, h};
	red = 255;
	green = 255;
	blue = 255;
};
Sprite::Sprite(int x, int y, int w, int h, SDL_Texture* t):x(x),y(y),w(w),h(h),tex(t){
	rect = {x, y, w, h};
	red = 255;
	green = 255;
	blue = 255;
};

void Sprite::setTexture(SDL_Texture* t){
	tex = t;
}

void Sprite::render(SDL_Renderer* r){
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	if (tex == NULL){
		SDL_SetRenderDrawColor(
			r, red, 
			green, blue, 0xFF
		);
		SDL_RenderFillRect(
			r, &rect
		);
	} else {
		SDL_RenderCopy( r, tex, NULL, &rect );
	}
}
