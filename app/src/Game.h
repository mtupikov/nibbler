#pragma once

#include "Snake.h"
#include "Map.h"
#include "GameModel.h"
#include "GuiManager.h"

#include <memory>

class Game final {
public:
	Game(int width, int height);
	void gameLoop();

private:
	std::unqiue_ptr<GuiManager> m_guiManager;
	std::unqiue_ptr<GameModel> m_model;
};

