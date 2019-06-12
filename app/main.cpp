#include <memory>
#include <iostream>
#include <string>
#include <time.h>
#include <cctype>
#include <algorithm>

#include "Game.h"

namespace {

struct Parameters final {
    int width;
    int height;
};

int usage() {
    std::cout << "Usage: ./nibbler [60 <= width <= 10] [60 <= height <= 10]" << std::endl;
    return -1;
}

bool isStrDigit(const std::string&& str) {
    return std::find_if(str.begin(), str.end(), [](char c) {
        return std::isdigit(c);
    }) != str.end();
}

Parameters getMapSize(char** argv) {
    if (!isStrDigit(argv[1]) || !isStrDigit(argv[2])) {
        return {-1, -1};
    }

    return {std::stoi(argv[1]), std::stoi(argv[2])};
}

}

int	main(int argc, char** argv){
	if (argc != 3) {
		return usage();
	}

    std::unique_ptr<Game> game;

	srand(static_cast<unsigned int>(time(nullptr)));

	try {
        auto params = getMapSize(argv);

        if (params.width < 10 || params.width > 60 || params.height < 10 || params.height > 60) {
			return usage();
		}

        game.reset(new Game(params.width, params.height));
		game->gameLoop();
    } catch (std::exception& e) {
		std::cout << e.what() << std::endl;
    } catch (...) {}

	return 0;
}
