#pragma once

#include "IGui.h"

#include <SFML/Window.hpp>

class SFMLib : public IGui {
public:
    SFMLib() = default;
    virtual ~SFMLib() override = default;

    sf::Window* getWindow() const;
    void setWindow(sf::Window* window);

    void display(std::shared_ptr<GameModel>& model) override;
    void checkControls(std::shared_ptr<GameModel>& model) override;

private:
    sf::Window* m_window{ nullptr };
};
