#include "Snake.h"
#include "Game.h"

#include <iostream>
#include <memory>

int usage() {
	std::cout << "Usage: ./nibbler [60 <= width <= 10] [60 <= height <= 10]" << std::endl;
	return (1);
}

bool isStrDigit(char* str) {
	while (*str) {
		if (!std::isdigit(*str)) {
			return false;
		}

		str++;
	}

	return true;
}

int *getMapSize(char **argv) {
	if (!isStrDigit(argv[1]) || !isStrDigit(argv[2])) {
		return nullptr;
	}

	auto* mapSize = new int[2];
	mapSize[0] = std::stoi(argv[1]);
	mapSize[1] = std::stoi(argv[2]);
	return mapSize;
}

int	main(int argc, char **argv){
	if (argc != 3) {
		return usage();
	}

	std::unqiue_ptr<Game> game;

	srand(static_cast<unsigned int>(time(nullptr)));

	try {
		int* mapSize = getMapSize(argv);

		if (mapSize == nullptr || mapSize[0] < 10 || mapSize[0] > 60 || mapSize[1] < 10 || mapSize[1] > 60) {
			delete mapSize;
			return usage();
		}

		game.reset(new Game(mapSize[0], mapSize[1]));
		delete mapSize;
		game->gameLoop();
    } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
