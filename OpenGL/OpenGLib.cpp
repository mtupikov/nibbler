#include "OpenGLib.h"

#include "GameModel.h"

#include <iostream>

//sf::Window* SFMLib::getWindow() const {
//    return m_window;
//}

//void SFMLib::setWindow(sf::Window* window) {
//    m_window = window;
//}

extern "C" {

IGui* allocator(int x, int y) {
    auto gui = new OpenGLib();

    return gui;
}

void deleter(IGui* gui) {
    auto sfmlGui = dynamic_cast<OpenGLib*>(gui);
    delete sfmlGui;
}

}

void OpenGLib::display(std::shared_ptr<GameModel>& model) {

}

void OpenGLib::checkControls(std::shared_ptr<GameModel>& model) {

}


