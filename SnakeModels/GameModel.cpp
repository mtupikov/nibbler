#include "GameModel.h"

#include "Map.h"
#include "Snake.h"

GameModel::GameModel(int width, int height) {
    m_map = Map::getInstance(width, height);
	m_snake.reset(new Snake(width / 2, height / 2));
	m_lib = DisplayLibrary::SDL;
    m_quit = false;
	m_score = 0;
}

std::shared_ptr<Snake> GameModel::getSnake() const{
	return m_snake;
}

std::shared_ptr<Map> GameModel::getMap() const{
	return m_map;
}

void GameModel::setLib(DisplayLibrary& lib) {
	m_lib = lib;
}

DisplayLibrary GameModel::getLib() const{
	return m_lib;
}

bool GameModel::isQuit() const{
	return m_quit;
}

void GameModel::quit() {
	m_quit = true;
}

std::shared_ptr<GameModel> GameModel::m_gameModel{ nullptr };

std::shared_ptr<GameModel> GameModel::getInstance(int x, int y) {
    if (m_gameModel) {
        return m_gameModel;
	}

    m_gameModel.reset(new GameModel(x, y));

    return m_gameModel;
}

std::shared_ptr<GameModel> GameModel::getInstance() {
	return getInstance(20, 20);
}

int GameModel::getScore() const {
	return m_score;
}

void GameModel::incScore() {
	++m_score;
}
