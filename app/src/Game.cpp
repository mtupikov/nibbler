#include "Game.h"

#include "Snake.h"
#include "Map.h"
#include "GameModel.h"

#include <iostream>

Game::Game(int width, int height) {
    m_model = GameModel::getInstance(width, height);
	m_guiManager.reset(new GuiManager());
}

void Game::gameLoop() {
    auto map = m_model->getMap();
    m_guiManager->loadGui(guiLibraries::sdlLibrary, map->getWidth(), map->getHeight());

	while (!m_model->isQuit()) {
        auto gui = m_guiManager->getGui();
        gui->checkControls(m_model);
		m_model->getSnake()->moveSnake();

        if (m_model->getSnake()->checkFoodBlockCollision(*map->getFoodBlock().get())) {
            map->relocateFood(m_model->getSnake()->getSnakeList());
			m_model->incScore();
		}

        gui->display(m_model);
	}
}
