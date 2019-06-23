#include "Game.h"

#include "Snake.h"
#include "Map.h"
#include "GameModel.h"

#include <iostream>

Game::Game(int width, int height) {
    m_model = GameModel::getInstance(width, height);
	m_guiManager = std::make_unique<GuiManager>();
}

void Game::gameLoop() {
    auto map = m_model->getMap();
    loadGui(DisplayLibrary::SDL);

	while (!m_model->isQuit()) {
	    auto oldLib = m_model->getLib();

        m_guiManager->getGui()->checkControls(m_model);
		m_model->getSnake()->moveSnake();

		if (oldLib != m_model->getLib()) {
            loadGui(m_model->getLib());
		}

        if (m_model->getSnake()->checkFoodBlockCollision(*map->getFoodBlock().get())) {
            map->relocateFood(m_model->getSnake()->getSnakeList());
			m_model->incScore();
		}

        m_guiManager->getGui()->display(m_model);
	}
}

void Game::loadGui(DisplayLibrary lib) {
    auto map = m_model->getMap();

    std::string libraryStr;

    switch (lib) {
        case DisplayLibrary::SDL:
            libraryStr = guiLibraries::sdlLibrary;
            break;
        case DisplayLibrary::SFML:
            libraryStr = guiLibraries::sfmlLibrary;
            break;
        case DisplayLibrary::GLFW:
            libraryStr = guiLibraries::openGLLibrary;
            break;
    }

    m_guiManager->loadGui(libraryStr, map->getWidth(), map->getHeight());
}