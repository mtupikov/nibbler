#pragma once

#include "Block.h"

class FoodBlock : public Block {
public:
	FoodBlock(int x, int y, BlockType type);
	~FoodBlock() override = default;
	void relocateFood(int x, int y);
};
