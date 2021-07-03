// Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include "window.h" 
#include "player.h" 
#include <SDL_image.h>


/*
	This method controls the player and the window interaction and takes care of that the input for these happens seperatly and 
	nothing gets fucked up. 
*/
void pollEvents(Window& window, Player& player)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		window.pollEvents(event);
		player.pollEvents(event);
	}
}


/*
	Main method, pretty simple, it creates the window, loads the players image and handles their inputs
*/
int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	Window window("Space invador", 800, 600);
	Player player(window, 150, 120, 100, 100, "C:/Users/Admin/Desktop/SpaceInvader_Engine/Spaceinvador_Engine/res/a.bmp");
	
	while (!window.is_closed()) {
		pollEvents(window, player);
		window.showWindow();
		player.createPlayer();
	}

	return 0;
}
