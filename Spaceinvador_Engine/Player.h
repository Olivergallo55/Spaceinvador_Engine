#pragma once
#include "Window.h"

class Player : Window
{
public:
	Player(){}
	Player(const Window& window, int w, int h, int x, int y);
	Player(const Window& window, int w, int h, int x, int y, const std::string& image_path);
	~Player();
	void createPlayer();
	void pollEvents(SDL_Event& event);


private:
	int _w, _h = 0;
	int _x, _y = 0;
	SDL_Texture* player_texure = nullptr;
};
