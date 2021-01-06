// Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "window.h" 
#include "player.h" 


void pollEvents(Window &window, Player &player)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		player.pollEvents(event);
		window.pollEvents(event);
	}
}


int main(int argc, char** argv)
{
	Window window("Space invador", 800, 600);
	Player player(window, 150, 90, 370, 521, "C:/Users/Admin/Desktop/C++ SU/Engine/res/spaceinvader.png");

	while (!window.is_closed())
	{
		pollEvents(window, player);
		player.draw();
		window.background();
	}
	
	return 0;
}
