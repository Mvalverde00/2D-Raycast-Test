#include <vector>
#include <SDL.h>


// Takes a 2D vector defining a map, i.e.:
// 0110100
// 0011100
// 0000111
// Where 1 denotes an open space and 0 denotes a wall
// And generates a vector of lines which outline the space
std::vector<std::vector<SDL_Point>> arrToLines(std::vector<std::vector<int>> maze) {

	int CELL_SIZE = 40; // Every cell will have dimensions CELL_SIZE x CELL_SIZE

	std::vector<std::vector<SDL_Point>> lines;

	for (int rowN = 0; rowN < maze.size(); rowN++) {
		for (int cellN = 0; cellN < maze[rowN].size(); cellN++) {
			if (maze[rowN][cellN] == 0) {

				if(rowN != 0 && maze[rowN-1][cellN] != 0)
					lines.push_back(std::vector<SDL_Point> { SDL_Point{CELL_SIZE*cellN, CELL_SIZE*rowN}, SDL_Point{CELL_SIZE*(cellN+1), CELL_SIZE*rowN}  } ); // Top


				if(rowN != (maze.size() - 1) && maze[rowN+1][cellN] != 0)
					lines.push_back(std::vector<SDL_Point> { SDL_Point{CELL_SIZE*cellN, CELL_SIZE*(rowN+1)}, SDL_Point{CELL_SIZE*(cellN+1), CELL_SIZE*(rowN+1)}  } ); // Bottom

				if(cellN != 0 && maze[rowN][cellN-1] != 0)
					lines.push_back(std::vector<SDL_Point> { SDL_Point{CELL_SIZE*cellN, CELL_SIZE*rowN}, SDL_Point{CELL_SIZE*cellN, CELL_SIZE*(rowN+1)}  } ); // Left

				if(cellN != (maze[rowN].size() - 1) && maze[rowN][cellN+1] != 0)
					lines.push_back(std::vector<SDL_Point> { SDL_Point{CELL_SIZE*(cellN+1), CELL_SIZE*rowN}, SDL_Point{CELL_SIZE*(cellN+1), CELL_SIZE*(rowN+1)}  } ); // Right
			}
		}
	}

	return lines;
};