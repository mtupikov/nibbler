#include "Snake.h"

#include "GameModel.h"
#include "SnakeBlock.h"
#include "FoodBlock.h"
#include "Map.h"

#include <iostream>

Snake::Snake(int x, int y) {
	m_snakeDirection = Directions::Up;
	m_snakeBlocks.push_front(SnakeBlockPtr(new SnakeBlock(x, y, BlockType::Snake, true)));

	for (int i = 0; i < 3; i++) {
		m_snakeBlocks.push_back(SnakeBlockPtr(new SnakeBlock(x, ++y, BlockType::Snake, false)));
	}
}

void Snake::setDirection(Directions dir) {
	m_snakeDirection = dir;
}

void Snake::moveSnake() {
    if (checkCollision(*m_snakeBlocks.begin()->get())) {
		GameModel::getInstance()->quit();
	}

	for (auto it = --m_snakeBlocks.end(); it != m_snakeBlocks.begin(); --it) {
		(*it)->getPosFrom(*(*std::prev(it, 1)));
	}

	auto it = m_snakeBlocks.begin();
	switch (m_snakeDirection) {
		case Directions::Up:
			(*it)->decY();
			break;
		case Directions::Down:
			(*it)->incY();
			break;
		case Directions::Left:
			(*it)->decX();
			break;
		case Directions::Right:
			(*it)->incX();
			break;
	}
}

void Snake::addBlockToTail() {
	SnakeBlock& lastBlock = *(*(--m_snakeBlocks.end()));
	int lastX = lastBlock.getX(),
		lastY = lastBlock.getY();

    switch (m_snakeDirection) {
		case Directions::Up:
			addBlock(lastX, --lastY);
			break;
		case Directions::Down:
			addBlock(lastX, ++lastY);
			break;
		case Directions::Left:
			addBlock(++lastX, lastY);
			break;
		case Directions::Right:
			addBlock(--lastX, lastY);
			break;
	}
}

void Snake::addBlock(int x, int y) {
	m_snakeBlocks.push_back(SnakeBlockPtr(new SnakeBlock(x, y, BlockType::Snake, false)));
}

std::list<SnakeBlockPtr>& Snake::getSnakeList() {
	return m_snakeBlocks;
}

bool Snake::checkBordersCollision(SnakeBlock& head) const{
	switch (m_snakeDirection) {
		case Directions::Up:
			if (head.getY() == 1)
				return true;
			break;
		case Directions::Down:
			if (head.getY() == Map::getHeight() - 2)
				return true;
			break;
		case Directions::Left:
			if (head.getX() == 1)
				return true;
			break;
		case Directions::Right:
			if (head.getX() == Map::getWidth() - 2)
				return true;
			break;
	}
	return false;
}

Directions Snake::getDirection() const {
	return m_snakeDirection;
}

bool Snake::checkSnakeBlocksCollision(SnakeBlock& head) const {
	switch (m_snakeDirection) {
		case Directions::Up:
			if (checkBlockLiesOnThisAxis(head.getX(), head.getY() - 1))
				return true;
			break;
		case Directions::Down:
			if (checkBlockLiesOnThisAxis(head.getX(), head.getY() + 1))
				return true;
			break;
		case Directions::Left:
			if (checkBlockLiesOnThisAxis(head.getX() - 1, head.getY()))
				return true;
			break;
		case Directions::Right:
			if (checkBlockLiesOnThisAxis(head.getX() + 1, head.getY()))
				return true;
			break;
	}
	return false;
}

bool Snake::checkBlockLiesOnThisAxis(int x, int y) const {
    for (auto it = ++m_snakeBlocks.begin(); it != m_snakeBlocks.end(); it++) {
		if ((*it)->getX() == x && (*it)->getY() == y) {
			return true;
		}
	}

	return false;
}

bool Snake::checkCollision(SnakeBlock& head) const {
	return checkSnakeBlocksCollision(head) || checkBordersCollision(head);
}

bool Snake::checkFoodBlockCollision(FoodBlock& foodBlock) {
	SnakeBlock& head = *(*m_snakeBlocks.begin());

	if (head.getX() == foodBlock.getX() && head.getY() == foodBlock.getY()) {
		addBlockToTail();
		return true;
	}

	return false;
}
