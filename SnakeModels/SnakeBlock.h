#pragma once

#include "Block.h"

class SnakeBlock : public Block {
public:
	SnakeBlock(int x, int y, BlockType type, bool isHead);
	~SnakeBlock() override = default;

	bool isHead();
	void incX();
	void decX();
	void incY();
	void decY();
	void getPosFrom(SnakeBlock& block);

private:
	bool m_isHead;
};
