#pragma once
#include "Player.h"
#include "Session.h"
#include "Window.h"
#include "Bullet.h"
#include <iostream>
#include<SDL.h>
#include <SDL_image.h>

class Player : public Object
{
public:
	Player(int x, int y, int w, int h, Window* win);
	~Player();
	void loadPicture(const char* image, Window* window);
	void showPicture(Window* window);
	void pollEvents(SDL_Event& event, Window* wind);
	static Player* getInstance(int x, int y, int w, int h,  Window* window);

private:
	SDL_Texture* texture; 
	void movement() {}
};

