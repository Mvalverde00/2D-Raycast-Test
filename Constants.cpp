#ifndef CONSTANTS_GUARD
#define CONSTANTS_GUARD

#include <SDL.h>
#include <array>

struct CONSTANTS {
	// The initial screen width and height, as well as the internal virtual screen dimensions, regardless of what the window is resized to.
	static const int SCREEN_WIDTH = 1280;
	static const int SCREEN_HEIGHT = 720;

	static constexpr float PI = 3.14159265;

	static constexpr SDL_Color RED = {255,0,0,255};
	static constexpr SDL_Color GREEN = {0,255,0,255};
	static constexpr SDL_Color BLUE = {0,0,255,255};
	static constexpr SDL_Color BLACK = {0,0,0,255};
	static constexpr SDL_Color WHITE = {255,255,255,255};
	static constexpr SDL_Color GRAY = {242,242,242,255};
	static constexpr SDL_Color PALE_YELLOW = {255,253,201,255};

};




#endif //Constants