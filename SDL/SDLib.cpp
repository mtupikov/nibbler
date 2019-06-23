#include "SDLib.h"

#include "Map.h"
#include "Snake.h"
#include "SnakeBlock.h"
#include "FoodBlock.h"
#include "GameModel.h"

#include <iostream>
#include <SDL.h>

namespace {

int blockSize = 20;
const std::string windowTitle{ "nibbler (SDL) Score: " };

}

SDL_Window* SDLib::getWindow() {
    return m_window;
}

void SDLib::setWindow(SDL_Window* window) {
    m_window = window;
}

extern "C" {

IGui* allocator(int x, int y) {
    auto* gui = new SDLib();

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << SDL_GetError() << std::endl;
        delete gui;
        return nullptr;
    }

    gui->setWindow(SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x * blockSize, y * blockSize, SDL_WINDOW_SHOWN));

    if (!gui->getWindow()) {
        std::cout << SDL_GetError() << std::endl;
        delete gui;
        return nullptr;
    }

    gui->setScreen(SDL_GetWindowSurface(gui->getWindow()));
    return gui;
}

void deleter(IGui* gui) {
    auto* sdlGui = dynamic_cast<SDLib*>(gui);

    SDL_DestroyWindow(sdlGui->getWindow());
    SDL_Quit();

    delete sdlGui;
}

}

void SDLib::display(std::shared_ptr<GameModel>& model) {
	int snakeLen = model->getScore() + 4;
    SDL_Delay(static_cast<size_t>(150 - snakeLen % 120));

    auto& map = *model->getMap();
    displayMap(map);
	displaySnake(model->getSnake());
	displayFood(map.getFoodBlock());

    SDL_UpdateWindowSurface(getWindow());

    std::string title = windowTitle + std::to_string(model->getScore());
    SDL_SetWindowTitle(getWindow(), title.c_str());
}

void SDLib::setScreen(SDL_Surface* screen) {
    m_screen = screen;
}

void SDLib::checkControls(std::shared_ptr<GameModel>& model) {
    SDL_Event event;
    auto snake = model->getSnake();

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
			model->quit();
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
				case SDLK_w:
                    if (snake->getDirection() != Directions::Up) {
                        snake->setDirection(Directions::Up);
                    }
					break;
				case SDLK_s:
                    if (snake->getDirection() != Directions::Up) {
                        snake->setDirection(Directions::Down);
                    }
					break;
				case SDLK_d:
                    if (snake->getDirection() != Directions::Left) {
                        snake->setDirection(Directions::Right);
                    }
					break;
				case SDLK_a:
                    if (snake->getDirection() != Directions::Right) {
                        snake->setDirection(Directions::Left);
                    }
					break;
                case SDLK_2:
                    model->setLib(DisplayLibrary::SFML);
                    break;
                case SDLK_3:
                    model->setLib(DisplayLibrary::GLFW);
                    break;
				default:
					break;
			}
		}
	}
}

void SDLib::displayMap(Map& map) {
    auto& mapBlocks = map.getMapBlocks();
    for (auto& block : mapBlocks) {
		SDL_Rect rect{};
		rect.x = block->getX() * blockSize;
		rect.y = block->getY() * blockSize;
		rect.w = blockSize;
		rect.h = blockSize;
		switch (block->getType()) {
            case BlockType::Surface:
                SDL_FillRect(m_screen, &rect, 0x000000);
				break;
            case BlockType::Wall:
                SDL_FillRect(m_screen, &rect, 0xFF0000);
				break;
			default:
				break;
		}
	}
}

void SDLib::displaySnake(const std::shared_ptr<Snake>& model) {
    auto snakeBlocks = model->getSnakeList();
    for (auto& block : snakeBlocks) {
		SDL_Rect rect{};
		rect.x = block->getX() * blockSize;
		rect.y = block->getY() * blockSize;
		rect.w = blockSize;
		rect.h = blockSize;

        if (block->isHead()) {
            SDL_FillRect(m_screen, &rect, 0x00FF00);
        } else {
            SDL_FillRect(m_screen, &rect, 0x00CC00);
        }
    }
}

void SDLib::displayFood(const FoodBlockPtr& foodBlock) {
	SDL_Rect rect{};
    rect.x = foodBlock->getX() * blockSize;
    rect.y = foodBlock->getY() * blockSize;
	rect.w = blockSize;
	rect.h = blockSize;

    SDL_FillRect(m_screen, &rect, 0xCCCC00);
}
