#include "Player.h"
#include "Window.h"
#include <iostream>
#include<SDL.h>
#include <SDL_image.h>


Player::Player(int x, int y, int w, int h, const char* image, Window& win): Object{x,y,w,h}
{
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	image = "C:/Users/Admin/Desktop/TestEngine/TestEngine/3.jpg";

	auto surface = IMG_Load(image);
	texture = IMG_LoadTexture(win.getRenderer(), "C:/Users/Admin/Desktop/TestEngine/TestEngine/3.jpg");
	SDL_FreeSurface(surface);
}

//shows the player on the window
void Player::showPlayer(Window& winds)
{
	SDL_Rect rect = getPosition();
	SDL_RenderCopy(winds.getRenderer(), texture, NULL, &rect);
}


//Controls the player so it can move left and right
void Player::pollEvents(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			position.x -= 10;
			break;
		case SDLK_RIGHT:
			position.x += 10;
			break;
		}
	}
}

Player::~Player()
{
	SDL_DestroyTexture(texture);
}
