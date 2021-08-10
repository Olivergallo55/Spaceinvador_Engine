#include "Bullet.h"

Bullet::Bullet(int x, int y, int w, int h, Window* wind) : Object{x,y,w,h}
{
	const char* image = "C:/Users/Admin/Desktop/SpaceInvader_Engine/Spaceinvador_Engine/laser.jpg";
	loadPicture(image, wind);
}

Bullet::~Bullet()
{
	SDL_DestroyTexture(texture);
}

void Bullet::loadPicture(const char* image, Window* window)
{
	texture = IMG_LoadTexture(window->getRenderer(), "C:/Users/Admin/Desktop/SpaceInvader_Engine/Spaceinvador_Engine/laser.jpg");
}

void Bullet::showPicture(Window* winds)
{
	SDL_Rect rect = getPosition();
	SDL_RenderCopy(winds->getRenderer(), texture, NULL, &rect);
}

Bullet* Bullet::getInstance(int x, int y, int w, int h, Window* wind)
{
	return new Bullet(x,y,w,h, wind);
}



