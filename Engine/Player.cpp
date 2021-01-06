#include "Player.h"
#include <iostream>
#include<SDL.h>
#include <SDL_image.h>


Player::Player(const Window &window,int w, int h, int x, int y,int r, int g, int b, int a) :
	Window(window), _w(w), _h(h), _x(370), _y(480), _r(r), _g(g), _b(b), _a(a)
{
}

Player::Player(const Window& window, int w, int h, int x, int y, const std::string& image_path) :
	Window(window), _w(w), _h(h), _x(x), _y(y)
{
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface\n";
	}
	player_texure = SDL_CreateTextureFromSurface(renderer, surface);

	if (!player_texure) {
		std::cerr << "Failed to create texture\n";
	}
	SDL_FreeSurface(surface);
}

void Player::draw() const
{	
	SDL_Rect rect = { _x,_y,_w,_h };

	if (player_texure) {
		SDL_RenderCopy(renderer, player_texure, nullptr, &rect);
	}else{

	SDL_SetRenderDrawColor(renderer, _r,_g,_b,_a);
	SDL_RenderFillRect(renderer, &rect);
	 }
}

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
