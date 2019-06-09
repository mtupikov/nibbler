#pragma once

#include "model/GameModel.h"

class IGui {
public:
    virtual ~IGui();

	virtual void display(GameModel* model) = 0;
	virtual void checkControls(GameModel* model) = 0;
};
