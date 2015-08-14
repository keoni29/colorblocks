#ifndef __sprite
#define __sprite
	class Sprite {
	public:
		Sprite(int x, int y, int w, int h);
		Sprite(int x, int y, int w, int h, SDL_Texture* t);
		void setTexture(SDL_Texture* t);
		void render(SDL_Renderer* r);
		int x, y, w, h;
		int red, green, blue;
	private:
		SDL_Rect rect;
		SDL_Texture* tex;
	};
#endif