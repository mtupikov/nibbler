#pragma once

#include "GuiManager.h"

#include <memory>

class GameModel;

class Game final {
public:
	Game(int width, int height);
	void gameLoop();

private:
    std::unique_ptr<GuiManager> m_guiManager;
    std::shared_ptr<GameModel> m_model;
};
