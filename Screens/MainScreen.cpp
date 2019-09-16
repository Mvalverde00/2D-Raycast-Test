#include "../ScreenManager/GameScreen.h"
#include "../Constants.cpp"
#include "../Utility.cpp"

//#include "../RayTracing/Ray.cpp"
#include "../RayTracing/Wall.cpp"
#include "../RayTracing/MoveableLight.cpp"

#include "../WorldGen/Converter.cpp"

#include <stdlib.h> // rand
#include <time.h> // Seed rand

#include <SDL.h>

class MainScreen : public GameScreen {

	MoveableLight* light;
	std::vector<Wall> walls;


public:

	MainScreen(){

		light = new MoveableLight(SDL_Point {300,300}, 360);


		// Create a wall along the edge of the screen
		
		walls.push_back( Wall {SDL_Point {0,0}, SDL_Point {0,CONSTANTS::SCREEN_HEIGHT} } );
		walls.push_back( Wall {SDL_Point {0,0}, SDL_Point {CONSTANTS::SCREEN_WIDTH,0} } );
		walls.push_back( Wall {SDL_Point {0,CONSTANTS::SCREEN_HEIGHT}, SDL_Point {CONSTANTS::SCREEN_WIDTH,CONSTANTS::SCREEN_HEIGHT} } );
		walls.push_back( Wall {SDL_Point {CONSTANTS::SCREEN_WIDTH,0}, SDL_Point {CONSTANTS::SCREEN_WIDTH,CONSTANTS::SCREEN_HEIGHT} } );
		

		std::vector<std::vector<SDL_Point>> lines = arrToLines( std::vector<std::vector<int>> {	 {0,1,0,0,0},
																								 {0,1,1,1,0},
																								 {0,1,0,1,0},
																								 {0,1,1,1,1},
																								 {0,0,0,0,1},
																								 {0,0,0,0,1} });
		for ( std::vector<SDL_Point> line : lines ) {
			walls.push_back( Wall {line[0], line[1]} );
		}
		

		//walls.push_back( Wall {SDL_Point {400,400}, SDL_Point {500,400} } );
		//walls.push_back( Wall {SDL_Point {500,300}, SDL_Point {500,400} } );


	};


	void loadContent(SDL_Renderer *renderer){



	};
	void unloadContent(){};

	void processInput(SDL_Event* e){
		light->processInput(e);
	};

	// Does each ray hit a wall?  If so, where?
	void update(Uint32 deltaT){

		light->update(deltaT, walls);

	};

	// Show the walls and rays
	void render(SDL_Renderer* renderer){

		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
		SDL_SetRenderDrawColor(renderer, CONSTANTS::GREEN.r, CONSTANTS::GREEN.g, CONSTANTS::GREEN.b, 0);
		for (Wall w : walls) {
			SDL_RenderDrawLine(renderer, w.start.x, w.start.y, w.end.x, w.end.y);
		}

		light->render(renderer);

	};

};