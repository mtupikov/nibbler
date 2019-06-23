#pragma once

#include "IGui.h"

#include "Ptrs.h"

namespace sf {
    class RenderWindow;
}

class Map;
class Snake;

class SFMLib : public IGui {
public:
    SFMLib() = default;
    virtual ~SFMLib() override = default;

    sf::RenderWindow* getWindow() const;
    void setWindow(sf::RenderWindow* window);

    void display(std::shared_ptr<GameModel>& model) override;
    void checkControls(std::shared_ptr<GameModel>& model) override;

private:
    void displayMap(Map& map);
    void displaySnake(const std::shared_ptr<Snake>& model);
    void displayFood(const FoodBlockPtr& foodBlock);

    sf::RenderWindow* m_window{ nullptr };
};
