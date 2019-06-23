#pragma once

#include "GuiManager.h"

#include <memory>

class GameModel;
enum class DisplayLibrary;

class Game final {
public:
	Game(int width, int height);
	void gameLoop();

private:
    void loadGui(DisplayLibrary lib);

    std::unique_ptr<GuiManager> m_guiManager;
    std::shared_ptr<GameModel> m_model;
};
