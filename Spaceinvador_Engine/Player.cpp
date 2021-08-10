#include "Player.h"


Player::Player(int x, int y, int w, int h, Window* win) : Object{x,y,w,h}
{
	const char* image = "C:/Users/Admin/Desktop/TestEngine/TestEngine/3.jpg";

	loadPicture(image, win); 

	/*
	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;

	SDL_SetRenderDrawColor(win.renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(win.renderer, &r);
	*/
}

//shows the player on the window
void Player::showPicture(Window* winds)
{
	SDL_Rect rect = getPosition();
	SDL_RenderCopy(winds->getRenderer(), texture, NULL, &rect);
}


//Controls the player so it can move left and right
void Player::pollEvents(SDL_Event& event, Window* wind)
{
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			position.x -= 10;
			if (position.x <= 0)
				setPosition(0, position.y, 75, 50);
			break;
		case SDLK_RIGHT:
			position.x += 10;
			if (position.x >= 730)
				setPosition(730, position.y, 75,50);
			break;
		case SDLK_SPACE:
			std::cout << "im working look at me man\n";
			Bullet* b = new Bullet(position.x,position.y -30,50,50, wind); //new bullet
			ses.add(b); //add it to the shown components 
			break;
		}
	}
}

Player* Player::getInstance(int x, int y, int w, int h, Window* window)
{
	return new Player(x,y,w,h,window);
}

//destroy the texture
Player::~Player()
{
	SDL_DestroyTexture(texture);
}

//loads the picture
void Player::loadPicture(const char* image, Window* window)
{
	texture = IMG_LoadTexture(window->getRenderer(), "C:/Users/Admin/Desktop/TestEngine/TestEngine/3.jpg");
}
