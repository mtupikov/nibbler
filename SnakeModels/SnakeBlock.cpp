#include "SnakeBlock.h"

SnakeBlock::SnakeBlock(int x, int y, BlockType type, bool isHead) :
	Block(x, y, type),
	m_isHead(isHead)
{
}

bool SnakeBlock::isHead()  {
	return m_isHead;
}

void SnakeBlock::incX() {
	setX(getX() + 1);
}

void SnakeBlock::decX() {
	setX(getX() - 1);
}

void SnakeBlock::incY() {
	setY(getY() + 1);
}

void SnakeBlock::decY() {
	setY(getY() - 1);
}

void SnakeBlock::getPosFrom(SnakeBlock& block) {
	setX(block.getX());
	setY(block.getY());
}
