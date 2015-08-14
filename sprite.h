#ifndef __sprite
#define __sprite
	class Sprite {
	public:
		Sprite(int x, int y, int w, int h);
		void render(SDL_Renderer* r);
		int x, y, w, h;
		int red, green, blue;
	private:
		SDL_Rect rect;
	};
#endif