#include "Session.h" 
#define FPS 800 
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
	components.emplace_back(obj);
}

void Session::run()
{
	window = new Window("Space invador", 800, 600);  

	player = new Player(400, 550, 75, 50, window);
	add(player);
	in = new Invader(100, 100, 50, 55, window);
	add(in);
	invader_vector.push_back(in);
	Uint32 tickInterval = 1000 / FPS; 

	start = std::clock();

	while (!window->is_closed()) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval; 
		pollEvents(window, player);
		window->showWindow(); 
			
		/*
		while(check){ 
			for (unsigned int i = 0; i < window->w / 60; i++) {
					Invader* inv = new Invader(50 + (i * 55), 20, 40, 40, window);	
					add(inv); 					
			} 
			check = false; 
		}
		*/
		
		/*
		for (Object* c : components) { 
			if (Invader* invader = dynamic_cast<Invader*> (c)) { //--> check if the components type is an invador or not (otherwise all components would move)				

				
					if (c->getPosition().x != 0 && c->getPosition().y == 100) {
						c->setXY(c->position.x - 1, c->position.y);
					}

					else if (c->getPosition().x == 0 && c->getPosition().y != 200) {
						c->setXY(c->position.x, c->position.y + 1);
					}
					else if (c->getPosition().x >= 0 && c->getPosition().y == 200 && c->position.x != 756) {
						c->setXY(c->position.x + 2, c->position.y);
					
					}
					else if (c->getPosition().x >= 756 &&  c->getPosition().y != 250) {
						c->setXY(c->position.x, c->position.y + 1);
					}
					else if (c->getPosition().x != 0 && c->getPosition().y == 250) {
						c->setXY(c->position.x - 1, c->position.y);
					}	
			}
		} 
		*/ 

//################ COLLISION AND BULLETS START ################
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


		bool checkCollision = in->checkCollision(bullet);
		
			//################# COLLISION START #############################################
		if (checkCollision) {
			for (std::vector<Object*>::iterator c = components.begin(); c != components.end();) {
				if (Invader* invader = dynamic_cast<Invader*> (*c)) {
					player->bullets.erase(player->bullets.begin() + x);
					player->bullets.shrink_to_fit(); //fixes the capacity to avoid exception
					c = components.erase(c);
				}
				else
					++c; 
			}
		}
		//################# COLLISION END ###############################################
		

		if (duration >= 10)
			start = std::clock();
	}
}


Session ses; 
