#include "Map.h"

#include "Block.h"
#include "FoodBlock.h"
#include "SnakeBlock.h"

int Map::getHeight() {
	return m_height;
}

int Map::getWidth() {
	return m_width;
}

Map::Map(int width, int height) {
	m_width = width;
	m_height = height;

	for (auto i = 0; i < height; ++i) {
		for (auto j = 0; j < width; ++j) {
			BlockType type;

			if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
				type = BlockType::Wall;
			} else {
				type = BlockType::Surface;
			}

			m_mapBlocks.push_back(BlockPtr(new Block(j, i, type)));
		}
	}

	m_foodBlock.reset(new FoodBlock(2, 2, BlockType::Food));
}

std::list<BlockPtr>& Map::getMapBlocks() {
	return m_mapBlocks;
}

std::shared_ptr<Map> Map::getInstance(int width, int height) {
    if (m_map) {
        return m_map;
	}

    m_map.reset(new Map(width, height));

    return m_map;
}

std::shared_ptr<Map> Map::getInstance() {
    return getInstance(20, 20);
}


FoodBlockPtr Map::getFoodBlock() const {
	return m_foodBlock;
}

void Map::relocateFood(const std::list<SnakeBlockPtr>& snakeBlocks) {
	int randX = rand() % Map::getWidth() - 1,
		randY = rand() % Map::getHeight() - 1;

	if (checkForNewFoodLocation(snakeBlocks, randX, randY) || randX <= 0 || randY <= 0) {
		relocateFood(snakeBlocks);
	} else {
		m_foodBlock->relocateFood(randX, randY);
	}
}

bool Map::checkForNewFoodLocation(const std::list<SnakeBlockPtr>& snakeBlocks, int x, int y) {
    for (const SnakeBlockPtr& block : snakeBlocks) {
		if (block->getX() == x && block->getY() == y) {
			return true;
		}
	}

	return false;
}

std::shared_ptr<Map> Map::m_map{ nullptr };
int Map::m_width = 0;
int Map::m_height = 0;
