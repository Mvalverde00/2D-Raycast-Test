#ifndef UTILITY_GUARD
#define UTILITY_GUARD

#include <SDL.h>
#include <math.h>
#include<vector>

template <typename T>
std::vector<T> operator+(const std::vector<T> &A, const std::vector<T> &B)
{
    std::vector<T> AB;
    AB.reserve( A.size() + B.size() );                // preallocate memory
    AB.insert( AB.end(), A.begin(), A.end() );        // add A;
    AB.insert( AB.end(), B.begin(), B.end() );        // add B;
    return AB;
}

template <typename T>
std::vector<T> &operator+=(std::vector<T> &A, const std::vector<T> &B)
{
    A.reserve( A.size() + B.size() );                // preallocate memory without erase original data
    A.insert( A.end(), B.begin(), B.end() );         // add B;
    return A;                                        // here A could be named AB
}

bool operator==(const SDL_Point p1, const SDL_Point p2) {
	return (p1.x == p2.x && p1.y == p2.y);
}
bool operator<(const SDL_Point p1, const SDL_Point p2) {
	return (p1.y*1280 +p1.x < p2.y*1280 +p2.x);
}




class UTILITY{
public:

	static int getMagnitude(SDL_Point p) {
		return std::sqrt(p.x*p.x + p.y*p.y);
	}
	static int getMagnitudeSquared(SDL_Point p) {
		return p.x*p.x + p.y*p.y;
	}

	static int distanceSquared(int x0, int y0, int x1, int y1) {
		return (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0);
	}
	static int distance(int x0, int y0, int x1, int y1) {
		return std::sqrt( (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));
	}	

	// Returns the distance and direction to the intersection point, or an arbitrary point
	static SDL_Point getIntersectionDelta(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
		float denom = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);

		if (denom == 0) {
			return SDL_Point {-99999, -99999};
		}

		float t = ((x1-x3)*(y3-y4) - (y1-y3)*(x3-x4))/denom;

		if (t > 1 || t < 0)
			return SDL_Point {-99999,-99999};

		float u = -((x1-x2)*(y1-y3) - (y1-y2)*(x1-x3))/denom;

		if (u > 1 || u < 0)
			return SDL_Point {-99999,-99999};

		return SDL_Point {t*(x2-x1), t*(y2-y1)};


	}


};


#endif // UTILITY_GUARD