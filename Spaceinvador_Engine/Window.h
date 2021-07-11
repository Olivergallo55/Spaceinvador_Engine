#pragma once
#include <string>
#include <SDL.h>

class Window
{
public:
	Window(){}
	Window(const std::string& title, int w, int h);
	~Window();
	bool init();
	inline bool is_closed() const { return closed; }
	SDL_Renderer* renderer;
	SDL_Renderer* getRenderer() const { return renderer;  }
	void pollEvents(SDL_Event& event);
	void showWindow();

private:
	std::string title;
	int w = 800;
	int h = 600;
	bool closed = false;

	SDL_Window* window;

};

extern Window wind;
