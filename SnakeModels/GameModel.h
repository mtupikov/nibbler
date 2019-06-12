#pragma once

#include <memory>

class Snake;
class Map;

enum class DisplayLibrary {
	SDL
};

class GameModel final {
public:
    static std::shared_ptr<GameModel> getInstance(int x, int y);
    static std::shared_ptr<GameModel> getInstance();

	bool isQuit() const;
	void quit();
	std::shared_ptr<Snake> getSnake() const;
    std::shared_ptr<Map> getMap() const;
	DisplayLibrary getLib() const;
	void setLib(DisplayLibrary &lib);
	int getScore() const;
	void incScore();

private:
	GameModel(int x, int y);

	std::shared_ptr<Snake> m_snake;
    std::shared_ptr<Map> m_map;
    DisplayLibrary m_lib;
    int m_score;
	bool m_quit;

    static std::shared_ptr<GameModel> m_gameModel;
};
