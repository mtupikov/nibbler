#include "SFMLib.h"

#include "GameModel.h"

#include <iostream>

sf::Window* SFMLib::getWindow() const {
    return m_window;
}

void SFMLib::setWindow(sf::Window* window) {
    m_window = window;
}

extern "C" {

IGui* allocator(int x, int y) {
    auto gui = new SFMLib();
    gui->setWindow(new sf::Window(sf::VideoMode(static_cast<unsigned int>(x * 20), static_cast<unsigned int>(y * 20)), "nibbler"));
    return gui;
}

void deleter(IGui* gui) {
    auto sfmlGui = dynamic_cast<SFMLib*>(gui);
    delete sfmlGui;
}

}

void SFMLib::display(std::shared_ptr<GameModel>& model) {

}

void SFMLib::checkControls(std::shared_ptr<GameModel>& model) {
    sf::Event event;
    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            model.get()->quit();
            m_window->close();
        }
    }
}


