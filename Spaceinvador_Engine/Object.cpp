#include "Object.h"

void Object::setPosition(int x, int y, int w, int h)
{
	position.x = x;
	position.y = y;
	position.w = w;
	position.h = h;
}

Object::Object(int x, int y, int w, int h) : position{ x,y,w,h }
{
}
