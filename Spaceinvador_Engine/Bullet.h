#pragma once
#include "Object.h"
#include <iostream>

class Bullet : public Object
{
public:
	Bullet(int x, int y, int w, int h, Window* wind);
	~Bullet();
	void loadPicture(const char* image, Window* window);
	void showPicture(Window* winds);
	void pollEvents(SDL_Event& event){}
	static Bullet* getInstance(int x, int y, int w, int h, Window* wind);

private:
	SDL_Texture* texture;
};

