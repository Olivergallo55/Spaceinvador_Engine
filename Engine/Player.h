#pragma once

#include "Window.h"

class Player : public Window
{
public: 
	Player(const Window& window, int w, int h, int x, int y, int r, int g, int b, int a);
	Player(const Window& window, int w, int h, int x, int y, const std::string &image_path);
	~Player();
	void draw() const;
	void pollEvents(SDL_Event& event);


private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
	SDL_Texture* player_texure = nullptr;
};

