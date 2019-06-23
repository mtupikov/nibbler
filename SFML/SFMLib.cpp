#include "SFMLib.h"

#include "Map.h"
#include "Snake.h"
#include "SnakeBlock.h"
#include "FoodBlock.h"
#include "GameModel.h"

#include <iostream>
#include <cassert>
#include <SFML/Graphics.hpp>

namespace {

int blockSize = 40;
const std::string windowTitle{ "nibbler (SFML) Score: " };

}

sf::RenderWindow* SFMLib::getWindow() const {
    return m_window;
}

void SFMLib::setWindow(sf::RenderWindow* window) {
    m_window = window;
}

extern "C" {

IGui* allocator(int x, int y) {
    auto gui = new SFMLib();
    gui->setWindow(new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(x * blockSize), static_cast<unsigned int>(y * blockSize)), windowTitle.c_str()));

    if (!gui->getWindow()) {
        return nullptr;
    }

    auto desktop = sf::VideoMode::getDesktopMode();
    auto xCenter = desktop.width / 2 - gui->getWindow()->getSize().x / 2;
    auto yCenter = desktop.height / 2 - gui->getWindow()->getSize().y / 2;
    gui->getWindow()->setPosition(sf::Vector2i(xCenter, yCenter));

    return gui;
}

void deleter(IGui* gui) {
    auto sfmlGui = dynamic_cast<SFMLib*>(gui);
    sfmlGui->getWindow()->close();
    delete sfmlGui;
}

}

void SFMLib::display(std::shared_ptr<GameModel>& model) {
    int snakeLen = model->getScore() + 4;
    sf::Time delayTime = sf::milliseconds(150 - snakeLen % 120);
    sf::sleep(delayTime);

    auto& map = *model->getMap();
    displayMap(map);
    displaySnake(model->getSnake());
    displayFood(map.getFoodBlock());

    m_window->display();

    m_window->setTitle(windowTitle + std::to_string(model->getScore()));
}

void SFMLib::checkControls(std::shared_ptr<GameModel>& model) {
    sf::Event event;
    auto snake = model->getSnake();

    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
            model->quit();
        } else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::W:
                    if (snake->getDirection() != Directions::Up) {
                        snake->setDirection(Directions::Up);
                    }
                    break;
                case sf::Keyboard::S:
                    if (snake->getDirection() != Directions::Up) {
                        snake->setDirection(Directions::Down);
                    }
                    break;
                case sf::Keyboard::A:
                    if (snake->getDirection() != Directions::Right) {
                        snake->setDirection(Directions::Left);
                    }
                    break;
                case sf::Keyboard::D:
                    if (snake->getDirection() != Directions::Left) {
                        snake->setDirection(Directions::Right);
                    }
                    break;
                case sf::Keyboard::Num1:
                    model->setLib(DisplayLibrary::SDL);
                    break;
                case sf::Keyboard::Num3:
                    model->setLib(DisplayLibrary::GLFW);
                    break;
                default:
                    break;
            }
        }
    }
}

void SFMLib::displayMap(Map& map) {
    auto& mapBlocks = map.getMapBlocks();
    for (auto& block : mapBlocks) {
        sf::RectangleShape rect(sf::Vector2f(blockSize, blockSize));
        rect.setPosition(block->getX() * blockSize, block->getY() * blockSize);
        switch (block->getType()) {
            case BlockType::Surface:
                rect.setFillColor(sf::Color(255, 255, 255));
                break;
            case BlockType::Wall:
                rect.setFillColor(sf::Color(255, 0, 0));
                break;
            default:
                break;
        }
        m_window->draw(rect);
    }
}

void SFMLib::displaySnake(const std::shared_ptr<Snake>& model) {
    auto snakeBlocks = model->getSnakeList();
    for (auto& block : snakeBlocks) {
        sf::RectangleShape rect(sf::Vector2f(blockSize, blockSize));
        rect.setPosition(block->getX() * blockSize, block->getY() * blockSize);
        if (block->isHead()) {
            rect.setFillColor(sf::Color(0, 255, 0));
        } else {
            rect.setFillColor(sf::Color(0, 125, 0));
        }
        m_window->draw(rect);
    }
}

void SFMLib::displayFood(const FoodBlockPtr& foodBlock) {
    sf::RectangleShape rect(sf::Vector2f(blockSize, blockSize));
    rect.setPosition(foodBlock->getX() * blockSize, foodBlock->getY() * blockSize);
    rect.setFillColor(sf::Color(204, 204, 0));
    m_window->draw(rect);
}
