#include "FoodBlock.h"

FoodBlock::FoodBlock(int x, int y, BlockType type) : Block(x, y, type) {}

void FoodBlock::relocateFood(int x, int y) {
	setX(x);
	setY(y);
}
