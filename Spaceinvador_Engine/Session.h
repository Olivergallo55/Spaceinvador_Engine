#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "window.h" 
#include "player.h" 
#include "Object.h" 
#include <vector>

class Session
{
public:
	void add(Object* comp);
	void remove(Object* comp);
	void run();

private:
	std::vector<Object*> components;
	std::vector<Object*> removed;

};

extern Session ses;


