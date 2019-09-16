class Wall {

public:

	SDL_Point start;
	SDL_Point end;

	Wall(SDL_Point s, SDL_Point e) {

		start = s;
		end = e;
	}

};