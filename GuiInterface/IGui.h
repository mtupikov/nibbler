#pragma once

class GameModel;

#include <memory>

class IGui {
public:
    virtual ~IGui();

    virtual void display(std::shared_ptr<GameModel> model) = 0;
    virtual void checkControls(std::shared_ptr<GameModel> model) = 0;

    typedef IGui* allocator_t(int, int);
    typedef void deleter_t(IGui*);
};
