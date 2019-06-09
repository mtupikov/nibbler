#include "Game.h"

#include <iostream>

Game::Game(int width, int height) {
	m_model.reset(GameModel::getInstance(width, height));
	m_guiManager.reset(new GuiManager());

	std::string sdl = "SDL.dylib";

	m_guiManager->loadGui(sdl, width, height);
}

void Game::gameLoop() {
	while (!m_model->isQuit()) {
		IGui* gui = m_guiManager->getGui();
        gui->checkControls(m_model.get());
		m_model->getSnake()->moveSnake();

        if (m_model->getSnake()->checkFoodBlockCollision(*m_model->getMap()->getFoodBlock().get())) {
            m_model->getMap()->relocateFood(m_model->getSnake()->getSnakeList());
			m_model->incScore();
		}

        gui->display(m_model.get());
	}
}
