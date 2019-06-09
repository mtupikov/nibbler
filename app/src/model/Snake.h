#pragma once 

#include <list>

#include "Ptrs.h"

enum class Directions {
	Up,
	Down,
	Left,
	Right
};

class Snake final {
public:
	Snake(int x, int y);

	void setDirection(Directions dir);
	Directions getDirection() const;
	void moveSnake();
	std::list<SnakeBlockPtr>& getSnakeList() const;
	bool checkFoodBlockCollision(FoodBlock& foodBlock);

private:
	bool checkCollision(SnakeBlock& head) const;
	bool checkBordersCollision(SnakeBlock& head) const;
	bool checkSnakeBlocksCollision(SnakeBlock& head) const;
	bool checkBlockLiesOnThisAxis(int x, int y) const;
	void addBlockToTail();
	void addBlock(int x, int y);

	Directions m_snakeDirection;
	std::list<SnakeBlockPtr> m_snakeBlocks;
};


#endif