#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "window.h" 
#include "player.h" 

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

	Window window("Space invador", 800, 600);
	Player player(100, 100, 100, 100, "", window);
	Player pl(200, 200, 200, 200, "", window);

	while (!window.is_closed()) {
		pollEvents(window, player);
		window.showWindow();
		player.showPlayer(window);

		// Show what was drawn
		SDL_RenderPresent(window.getRenderer());

	}
      
	return 0;
}


   
