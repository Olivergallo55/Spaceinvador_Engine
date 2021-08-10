#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include "Window.h"

class Object
{

public:
	virtual ~Object(){}
	inline SDL_Rect getPosition() const { return position; }
	void setPosition(int x, int y, int w, int h);
	virtual void showPicture(Window* window){}
	SDL_Rect position;


protected:
	Object(int x, int y, int w, int h);
	virtual void pollEvents(SDL_Event& event){}
	virtual void movement(){}
};

