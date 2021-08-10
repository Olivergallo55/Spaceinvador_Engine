#include "Session.h"

/*
	This method controls the player and the window interaction and takes care of that the input for these happens seperatly and nothing gets messed up
*/
void pollEvents(Window* window, Player* player)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		window->pollEvents(event);
		player->pollEvents(event, window);
	}
}

//the added components list
void Session::add(Object* obj)
{
	components.push_back(obj);
}

//the deleted list
void Session::remove(Object* obj) {
	removed.push_back(obj);
}

void Session::run()
{
	Window* window = new Window("Space invador", 800, 600);

	Player* player = Player::getInstance(400, 550, 75, 50, window);
	add(player);

	while (!window->is_closed()) {
		pollEvents(window, player);
		SDL_RenderClear(window->renderer);
		window->showWindow();

		//render all components in the list
		for (auto c : components) {
			c->showPicture(window);
		}

		// Show what was drawn 
		SDL_RenderPresent(window->getRenderer());
	}
	std::cout << components.size();
}

Session ses;
