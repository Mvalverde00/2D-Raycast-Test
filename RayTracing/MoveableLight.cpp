#include "Light.cpp"

class MoveableLight : public Light {

	// The base light class already has a pos variable, so we just need to add velocity
	SDL_Point vel;

	int speed = 200; // pixels per second

public:

	MoveableLight(SDL_Point p, int nRays): Light(p, nRays) {
		vel = {0,0};


	}

	void processInput(SDL_Event* e) {

		if (e->type == SDL_KEYDOWN) {

			if (e->key.repeat !=0) return;

			switch (e->key.keysym.sym) {
				case SDLK_w:
					vel.y -= speed;
					break;
				case SDLK_s:
					vel.y += speed;
					break;
				case SDLK_a:
					vel.x -= speed;
					break;
				case SDLK_d:
					vel.x += speed;
					break;
			}
			
		} else if (e->type == SDL_KEYUP) {

			if (e->key.repeat !=0) return;

			switch (e->key.keysym.sym) {
				case SDLK_w:
					vel.y += speed;
					break;
				case SDLK_s:
					vel.y -= speed;
					break;
				case SDLK_a:
					vel.x += speed;
					break;
				case SDLK_d:
					vel.x -= speed;
					break;
			}
		}

		
	}

	void update(Uint32 deltaT, std::vector<Wall> w){
		updatePos(deltaT, w);
		updateRays(w);
	};

	// This function needs to be optimized
	// To root out walls that dont need to be checked.
	void updatePos(Uint32 deltaT, std::vector<Wall> walls){

		// No need to do any checks if there is no velocity
		if (vel.x != 0 || vel.y != 0){

			int dx = vel.x* (deltaT/1000.0);
			int dy = vel.y* (deltaT/1000.0);

			for (Wall w : walls) {

				//if( (w.start.x < pos.x || w.end.x < pos.x) && vel.x >= 0) continue;
				//else if( (w.start.x > pos.x || w.end.x > pos.x) && vel.x <= 0) continue;

				//if( (w.start.y < pos.y || w.end.y < pos.y) && vel.y >= 0) continue;
				//else if( (w.start.y > pos.y || w.end.y > pos.y) && vel.y <= 0) continue;

				//std::cout<<"Checking";

				SDL_Point p = UTILITY::getIntersectionDelta(pos.x, pos.y, pos.x + dx, pos.y + dy, w.start.x, w.start.y, w.end.x, w.end.y);

				std::cout<<"VECTOR TO INTERSECT: "<<p.x<<", "<<p.y<<"\n";

				if (p.x != -99999 && p.y != -99999) {

					std::cout<<"ORIGINAL DX, DY: "<<dx<<", "<<dy<<"\n";

					if(dx > 0) dx = p.x - 1;
					else if (dx < 0) dx = p.x + 1;

					if (dy > 0) dy = p.y - 1;
					else if (dy < 0) dy = p.y + 1;

					std::cout<<"NEW DX, DY: "<<dx<<", "<<dy<<"\n"<<"================\n";

					break;
				}

			}

			pos.x += dx;
			pos.y += dy;

			//std::cout<<vel.x<<", "<<(deltaT/1000.0)<<", "<< vel.x*(deltaT/1000.0) << "\n";

			//std::cout<<pos.x<<", "<<pos.y<<"\n";
		}
	};


	

};