#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "window.h" 
#include "player.h" 

/*
	This method controls the player and the window interaction and takes care of that the input for these happens seperatly and 
	nothing gets fucked up. 
*/
void pollEvents(Window& window)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		window.pollEvents(event);
	}
}


/*
	Main method, pretty simple, it creates the window, loads the players image and handles their inputs
*/
int main(int argc, char** argv)
	{

	Window window("Space invador", 800, 600);

	while (!window.is_closed()) {
		pollEvents(window);
		window.showWindow();

		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

		SDL_Rect rect;

		rect.x = 200;
		rect.y = 200;
		rect.h = 200;
		rect.w = 200;

		SDL_Surface* image = IMG_Load("C:/Users/Admin/Desktop/TestEngine/TestEngine/3.jpg");
		SDL_Texture* image_texture = SDL_CreateTextureFromSurface(window.renderer, image);
		SDL_FreeSurface(image);

		// Draw
		SDL_RenderCopy(window.renderer, image_texture, NULL, &rect);
		

		// Show what was drawn
		SDL_RenderPresent(window.renderer);
	}
      
	return 0;
}


   