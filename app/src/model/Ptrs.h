#pragma once

#include <memory>

class Block;
class FoodBlock;
class SnakeBlock;

using BlockPtr = std::shared_ptr<Block>;
using FoodBlockPtr = std::shared_ptr<FoodBlockPtr>;
using SnakeBlockPtr = std::shared_ptr<SnakeBlockPtr>;