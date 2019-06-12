#pragma once

#include <list>
#include <memory>

#include "Ptrs.h"

class Map {
public:
    static std::shared_ptr<Map> getInstance(int width, int height);
    static std::shared_ptr<Map> getInstance();

	static int getWidth();
	static int getHeight();

	std::list<BlockPtr>& getMapBlocks();
	FoodBlockPtr getFoodBlock() const;
	void relocateFood(const std::list<SnakeBlockPtr>& snakeBlocks);

private:
    static std::shared_ptr<Map> m_map;
    static int m_width;
	static int m_height;

	Map(int width, int height);
	bool checkForNewFoodLocation(const std::list<SnakeBlockPtr>& snakeBlocks, int x, int y);

	std::list<BlockPtr> m_mapBlocks;
	FoodBlockPtr m_foodBlock;
};
