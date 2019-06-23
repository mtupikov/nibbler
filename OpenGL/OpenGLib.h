#pragma once

#include "IGui.h"

#include "Ptrs.h"

class GLFWwindow;
class Map;
class Snake;

class OpenGLib : public IGui {
public:
    OpenGLib() = default;
    ~OpenGLib() override = default;

    GLFWwindow* getWindow() const;
    void setWindow(GLFWwindow* window);

    void display(std::shared_ptr<GameModel>& model) override;
    void checkControls(std::shared_ptr<GameModel>& model) override;

private:
    static void drawBlock(BlockPtr&& block);
    void displayMap(Map& map);
    void displaySnake(const std::shared_ptr<Snake>& model);
    void displayFood(const FoodBlockPtr& foodBlock);

    GLFWwindow* m_window{ nullptr };
};
