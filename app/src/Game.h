#pragma once

#include "model/Snake.h"
#include "model/Map.h"
#include "model/GameModel.h"
#include "GuiManager.h"

#include <memory>

class Game final {
public:
	Game(int width, int height);
	void gameLoop();

private:
    std::unique_ptr<GuiManager> m_guiManager;
    std::unique_ptr<GameModel> m_model;
};

