#include "Block.h"

Block::Block(int x, int y, BlockType type) :
	m_x(x),
	m_y(y),
	m_type(type)
{
}

int Block::getY() {
	return m_y;
}

int Block::getX() {
	return m_x;
}

BlockType Block::getType() {
	return m_type;
}

void Block::setY(int y) {
	m_y = y;
}

void Block::setX(int x) {
	m_x = x;
}
