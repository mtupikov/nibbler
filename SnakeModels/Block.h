#pragma once

#include <memory>

enum class BlockType {
	Surface,
	Wall,
	Snake,
	Food
};

class Block {
public:
	Block(int x, int y, BlockType type);
	virtual ~Block() = default;

	int getX();
	int getY();
	BlockType getType();

private:
	int m_x;
	int m_y;
	BlockType m_type;

protected:
	void setX(int x);
	void setY(int y);
};
