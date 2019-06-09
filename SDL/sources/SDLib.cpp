#include "SDLib.hpp"

SDLib::SDLib(): _window(nullptr), _screen(nullptr) {}

SDLib::~SDLib() {}

SDL_Window		*SDLib::getWindow() const
{
    return (_window);
}

void			SDLib::setWindow(SDL_Window *window)
{
    _window = window;
}

extern "C" IGui	*init(int x, int y)
{
	auto *gui = new SDLib();
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << SDL_GetError() << std::endl;
        delete (gui);
        return (nullptr);
    }
    gui->setWindow(SDL_CreateWindow("nibbler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x * 20, y * 20, SDL_WINDOW_SHOWN));
    if (gui->getWindow() == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        delete (gui);
        return (nullptr);
    }
	gui->setScreen(SDL_GetWindowSurface(gui->getWindow()));
    return (gui);
}

extern "C" void	close(IGui *gui)
{
    auto *sdlgui = dynamic_cast<SDLib *>(gui);

    SDL_DestroyWindow(sdlgui->getWindow());
    SDL_Quit();
    delete (sdlgui);
}

void		SDLib::display(GameModel *model)
{
	int snakeLen = model->getScore() + 4;
	SDL_Delay(static_cast<u_int32_t>(150 - snakeLen % 120));
	int blockSize = 20;
	Map &map = model->getMap();
	displayMap(map, blockSize);
	displaySnake(model, blockSize);
	displayFood(map, blockSize);
	SDL_UpdateWindowSurface(getWindow());
}

void SDLib::setScreen(SDL_Surface *screen) {
	_screen = screen;
}

void SDLib::checkControls(GameModel *model) {
	Snake *snake = model->getSnake();
	while (SDL_PollEvent(&_event)) {
		if (_event.type == SDL_QUIT || _event.key.keysym.sym == SDLK_ESCAPE)
			model->quit();
		if (_event.type == SDL_KEYDOWN) {
			switch (_event.key.keysym.sym) {
				case SDLK_w:
					if (snake->getDirection() != DOWN)
						snake->setDirection(UP);
					break;
				case SDLK_s:
					if (snake->getDirection() != UP)
						snake->setDirection(DOWN);
					break;
				case SDLK_d:
					if (snake->getDirection() != LEFT)
						snake->setDirection(RIGHT);
					break;
				case SDLK_a:
					if (snake->getDirection() != RIGHT)
						snake->setDirection(LEFT);
					break;
				default:
					break;
			}
		}
	}
}

void SDLib::displayMap(Map &map, int blockSize) {
	std::list<Block *> mapBlocks = map.getMapBlocks();
	for (Block *block : mapBlocks) {
		SDL_Rect rect{};
		rect.x = block->getX() * blockSize;
		rect.y = block->getY() * blockSize;
		rect.w = blockSize;
		rect.h = blockSize;
		switch (block->getType()) {
			case SURFACE:
				SDL_FillRect(_screen, &rect, 0x000000);
				break;
			case WALL:
				SDL_FillRect(_screen, &rect, 0xFF0000);
				break;
			default:
				break;
		}
	}
}

void SDLib::displaySnake(GameModel *model, int blockSize) {
	std::list<SnakeBlock *> snakeBlocks = model->getSnake()->getSnakeList();
	for (SnakeBlock *block : snakeBlocks) {
		SDL_Rect rect{};
		rect.x = block->getX() * blockSize;
		rect.y = block->getY() * blockSize;
		rect.w = blockSize;
		rect.h = blockSize;
		if (block->isItHead())
			SDL_FillRect(_screen, &rect, 0x00FF00);
		else
			SDL_FillRect(_screen, &rect, 0x00CC00);
	}
}

void SDLib::displayFood(Map &map, int blockSize) {
	FoodBlock block = map.getFoodBlock();
	SDL_Rect rect{};
	rect.x = block.getX() * blockSize;
	rect.y = block.getY() * blockSize;
	rect.w = blockSize;
	rect.h = blockSize;
	SDL_FillRect(_screen, &rect, 0xCCCC00);
}
