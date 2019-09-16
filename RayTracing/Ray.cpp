#include <SDL.h>
#include <math.h>

class Ray {

	// Define a ray by the vertex it originates from, the angle (in radians) at which it exits, and its magnitude
	SDL_Point vertex;
	float angle;
	int magnitude;

	float slope;
	int yOffset; 

	float x_comp;
	float y_comp;

	// A fake endpoint at an arbitrary point on the ray to use in calculations
	SDL_Point ghostEnd;

public:

	Ray(SDL_Point vertex, float angle){
		this->vertex = vertex;
		this->angle = angle;
		slope = std::tan(angle);

		yOffset =  vertex.y-slope*vertex.x;

		x_comp = std::cos(angle);
		y_comp = std::sin(angle);

		ghostEnd = { (int)(vertex.x +  x_comp*10000), (int)(vertex.y + y_comp*10000)};

		magnitude = 200;
	}


	void render(SDL_Renderer* renderer) {
		SDL_RenderDrawLine(renderer, vertex.x, vertex.y, vertex.x + x_comp*magnitude, vertex.y + y_comp*magnitude);
	}

	void setVert(SDL_Point p) {
		vertex = p;
		ghostEnd = { (int)(vertex.x +  x_comp*10000), (int)(vertex.y + y_comp*10000)};

	}

	void setMagnitude(int mag) {
		magnitude = mag;
	}
	int getMagnitude() {
		return magnitude;
	}

	int getX() {
		return vertex.x;
	}
	int getY() {
		return vertex.y;
	}

	int getEndX() {
		return ghostEnd.x;
	}
	int getEndY() {
		return ghostEnd.y;
	}


};