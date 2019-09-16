#include "Ray.cpp"
#include "../Constants.cpp"

#include <SDL.h>

class Light {
protected:
	SDL_Point pos;
	std::vector<Ray> rays;

	SDL_BlendMode mode;

public:

	Light(SDL_Point p, int nRays) {
		pos = p;

		float delta = 360/nRays;
		for(float i = 0; i < 360; i+= delta) {
			rays.push_back( Ray{p, i*CONSTANTS::PI/180} );
		}

		mode = SDL_ComposeCustomBlendMode(SDL_BLENDFACTOR_ZERO, SDL_BLENDFACTOR_ONE, SDL_BLENDOPERATION_ADD, SDL_BLENDFACTOR_ONE, SDL_BLENDFACTOR_ONE, SDL_BLENDOPERATION_ADD);

	}

	void updateRays(std::vector<Wall> walls) {

		// Used to determine which wall a ray should shine towards, if multiple walls are in its path.
		int currMag = 999999;

		for (Ray& r : rays) {

			//update Ray's position to the mouse cursor
			r.setVert(pos);


			for (Wall w : walls) {

				float denom = (r.getX() - r.getEndX())*(w.start.y - w.end.y) - (r.getY() - r.getEndY())*(w.start.x-w.end.x);

				if (denom == 0) continue;


				float t = ((r.getX() - w.start.x)*(w.start.y - w.end.y) - (r.getY() - w.start.y)*(w.start.x-w.end.x))/denom;
				if (t < 0) continue;


				float u = -( (r.getX()-r.getEndX())*(r.getY()-w.start.y) - (r.getY()-r.getEndY())*(r.getX()-w.start.x) )/denom;

				if (u > 1 || u < 0) continue;


				int mag = UTILITY::getMagnitude( SDL_Point{t*(r.getEndX()-r.getX()),t*(r.getEndY()-r.getY()) } );

				if (mag < currMag) {
					currMag = mag;
				}
			}

			r.setMagnitude(currMag+50);
			currMag = 999999;
		}

	}


	void render(SDL_Renderer* renderer) {

		SDL_SetRenderDrawBlendMode(renderer, mode);
		SDL_SetRenderDrawColor(renderer, CONSTANTS::WHITE.r, CONSTANTS::WHITE.g, CONSTANTS::WHITE.b, 100);
		for (Ray r : rays) {
			r.render(renderer);
		}
	}



};