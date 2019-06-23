#pragma once

#include "IGui.h"

#include "Ptrs.h"

class Map;
class Snake;
struct SDL_Window;
struct SDL_Surface;

class SDLib: public IGui {
public:
    SDLib() = default;
    ~SDLib() override = default;

    SDL_Window* getWindow();

    void setScreen(SDL_Surface* screen);
    void setWindow(SDL_Window* window);
    void display(std::shared_ptr<GameModel>& model) override;
    void checkControls(std::shared_ptr<GameModel>& model) override;

private:
    void displayMap(Map& map);
    void displaySnake(const std::shared_ptr<Snake>& model);
    void displayFood(const FoodBlockPtr& foodBlock);

    SDL_Window* m_window{ nullptr };
    SDL_Surface* m_screen{ nullptr };
};
