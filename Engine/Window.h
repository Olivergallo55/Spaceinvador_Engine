#pragma once
#include <string>
#include <SDL.h>

class Window
{
public:
	Window(const std::string &title, int w, int h);
	~Window();
	inline bool is_closed() const { return closed; }
	void pollEvents(SDL_Event& event);
	void background() const;

private: 
	bool init();

	std::string title;
	int w = 800;
	int h = 600;
	bool closed = false;

	SDL_Window* window = nullptr;

protected:
	SDL_Renderer* renderer = nullptr;
};

