#include "Window.h"
#include <SDL_image.h>
#include <iostream>

Window wind;

Window::Window(const std::string& title, int w, int h) :
	title(title), w(w), h(h)
{
	closed = !init();
}

//Decunstructor, destroys the renderers and quits the window
Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

//Controls the window so it can be quited
void Window::pollEvents(SDL_Event& event)
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

//set the background color of the window and clear the renderer
void Window::showWindow()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

//initilaze and create the window
bool Window::init()
{

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Failed to initilize SDL\n";
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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		std::cerr << "Failed to create window\n";
		return false;
	}

	return true;
}
