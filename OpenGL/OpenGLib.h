#pragma once

#include "IGui.h"

#include <gl/GL.h>

class OpenGLib : public IGui {
public:
    OpenGLib() = default;
    virtual ~OpenGLib() override = default;

    //sf::Window* getWindow() const;
    //void setWindow(sf::Window* window);

    void display(std::shared_ptr<GameModel>& model) override;
    void checkControls(std::shared_ptr<GameModel>& model) override;

private:
    //sf::Window* m_window{ nullptr };
};
