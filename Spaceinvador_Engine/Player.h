#pragma once
#include "Window.h"
#include "Object.h"

class Player : public Object
{
public:
	Player(int x, int y, int w, int h, const char* image, Window& win);
	~Player();
	void showPlayer(Window& window);
	void pollEvents(SDL_Event& event);


private:
	SDL_Texture* texture; 
};
