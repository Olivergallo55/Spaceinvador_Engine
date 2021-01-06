#include "Window.h"
#include <SDL_image.h>
#include <iostream>

Window::Window(const std::string& title, int w, int h) : 
	title(title), w(w), h(h)
{
	if (!init()) 
	{
		closed = true;
	}
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

void Window::pollEvents(SDL_Event &event)
{
	switch (event.type)
	{
	case SDL_QUIT:
		closed = true;
		break;
	case SDLK_ESCAPE:
		closed = true;
		break;
	default:
		break;
	}
}

void Window::background() const
{

//	SDL_RenderPresent(renderer);
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//SDL_RenderClear(renderer);

	
	SDL_RenderPresent(renderer);
	SDL_Surface* bgSurf = SDL_LoadBMP("C:/Users/Admin/Pictures/bg_space.bmp");
	SDL_Texture* bgTx = SDL_CreateTextureFromSurface(renderer, bgSurf);

	SDL_RenderCopy(renderer, bgTx, NULL, NULL);
	SDL_RenderClear(renderer);
	SDL_DestroyTexture(bgTx);
}

bool Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		std::cerr << "Failed to initilize SDL\n";
		return 0;
	}
	 
	if (IMG_Init(IMG_INIT_JPG) != IMG_INIT_JPG)
	{
		std::cerr << "Failed to initilaized image\n";
		return false;

	}

	window = SDL_CreateWindow(
	title.c_str(), SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, w, h, 0);

	if (window == nullptr) 
	{
		std::cerr << "Failed to create window\n";
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		std::cerr << "Failed to create renderer\n";
		return false;
	}


	return true;
}
