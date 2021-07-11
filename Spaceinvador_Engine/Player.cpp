#include "Player.h"
#include "Window.h"
#include <iostream>
#include<SDL.h>
#include <SDL_image.h>




Player::Player(const Window& window, int w, int h, int x, int y):
	Window(window), _w(w), _h(h), _x(x), _y(y)
{
}

Player::Player(const Window& window, int w, int h, int x, int y, const std::string& image_path) :
	Window(window), _w(w), _h(h), _x(x), _y(y)
{
	/*
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface\n";
	}
	player_texure = IMG_LoadTexture(renderer, "C:/Users/Admin/Desktop/TestEngine/TestEngine/3.jpg");

	if (!player_texure) {
		std::cerr << "Failed to create texture\n";
	}
	
	SDL_FreeSurface(surface);
	*/
}


void Player::createPlayer()
{
	SDL_Rect rect;

	rect.x = 200;
	rect.y = 200;
	rect.h = 200;
	rect.w = 200;

	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	SDL_Surface* image = IMG_Load("C:/Users/Admin/Desktop/TestEngine/TestEngine/3.jpg");
	SDL_Texture* image_texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	// Draw
	SDL_RenderCopy(renderer, image_texture, NULL, &rect);

	// Show what was drawn
	SDL_RenderPresent(renderer);
}


/*
	Controls the player so it can move left and right
*/
void Player::pollEvents(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			_x -= 10;
			break;
		case SDLK_RIGHT:
			_x += 10;
			break;
		}
	}
}

Player::~Player()
{
	SDL_DestroyTexture(player_texure);
}
