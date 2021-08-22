#include "Session.h" 
#define FPS 60
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
		ses.pollEvent(event); 
	}
}

bool check = true;

//the added components list
void Session::add(Object* obj)
{  
	components.emplace_back(obj);
}

void Session::run()
{
	window = new Window("Space invador", 800, 600);  

	player = new Player(400, 550, 75, 50, window);
	add(player);
	Uint32 tickInterval = 1000 / FPS; 

	start = std::clock();

	while (!window->is_closed()) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval; 
		pollEvents(window, player);
		window->showWindow(); 

			
		while(check){ 
			for (unsigned int i = 0; i < unsigned(window->w / 60); i++) {
					inv = new Invader(50 + (i * 55), 20, 40, 40, window);	
					invaders.push_back(inv); 	
					add(inv);
			} 
			check = false;  
		} 

		for (Object* c : components) {
				c->movement();
		}
	

//################ COLLISION AND BULLcETS START ################
		handleBullets();
//################ COLLISION AND BULLETS END  #################

		//render all components in the list 
		for (auto c : components) { 
			c->showPicture(window);
		}	

		// Show what was drawn 
		SDL_RenderPresent(window->getRenderer());
		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay); 
	}
	std::cout << components.size();
}

void Session::pollEvent(SDL_Event& event)
{

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
		case SDLK_r:
			bulletspeed++;
			std::cout << bulletspeed << std::endl; 
		}
	}
}

void Session::handleBullets() {
	duration = (std::clock() - start);

	for (unsigned int x = 0; x < player->bullets.size(); x++) {

		bullet = player->bullets[x];
		bulletspeed = 6;
		if (duration >= 10) 
		{
			SDL_Rect currentpos = bullet->getPosition();
			currentpos.y -= bulletspeed;
			bullet->position = currentpos;
		}

		if (bullet->position.y <= 0) {
			player->bullets.erase(player->bullets.begin() + x);
			player->bullets.shrink_to_fit(); //fixes the capacity to avoid exception
		}
		bullet->showPicture(window);


		//################# COLLISION START #############################################

		for (unsigned int i = 0; i < unsigned(invaders.size()); i++) {

			Invader* in = invaders[i];

			bool collision = in->checkCollision(bullet);

			if (collision) {
				in->alive = false;
				player->bullets.erase(player->bullets.begin() + x);
				invaders.erase(invaders.begin() + i);
				invaders.shrink_to_fit(); //fixes the capacity to avoid exception
				player->bullets.shrink_to_fit(); //fixes the capacity to avoid exception
			} 
		}
		//################# COLLISION END ###############################################

		if (duration >= 10)
			start = std::clock();
	}
}



Session ses; 

