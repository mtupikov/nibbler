#pragma once

#include "GameModel.h"

class IGui {
public:
	virtual void display(GameModel* model) = 0;
	virtual void checkControls(GameModel* model) = 0;
};
