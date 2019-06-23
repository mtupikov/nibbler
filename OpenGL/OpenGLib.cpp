#include "OpenGLib.h"

#include "Map.h"
#include "Snake.h"
#include "SnakeBlock.h"
#include "FoodBlock.h"
#include "GameModel.h"

#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <GLFW/glfw3.h>
#include <thread>

namespace {

int blockSize = 20;
const std::string windowTitle{ "nibbler (GLFW) Score: " };

}

GLFWwindow* OpenGLib::getWindow() const {
    return m_window;
}

void OpenGLib::setWindow(GLFWwindow* window) {
    m_window = window;
}

extern "C" {

IGui* allocator(int x, int y) {
    if (!glfwInit()) {
        return nullptr;
    }

    auto gui = new OpenGLib();

    gui->setWindow(glfwCreateWindow(x * blockSize, y * blockSize, windowTitle.c_str(), nullptr, nullptr));

    if (!gui->getWindow()) {
        glfwTerminate();
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwMakeContextCurrent(gui->getWindow());

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, x * blockSize, y * blockSize, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    auto desktop = glfwGetVideoMode(glfwGetPrimaryMonitor());
    auto xCenter = desktop->width / 2 - x * blockSize / 2;
    auto yCenter = desktop->height / 2 - y * blockSize / 2;
    glfwSetWindowPos(gui->getWindow(), xCenter, yCenter);

    return gui;
}

void deleter(IGui* gui) {
    auto openGLib = dynamic_cast<OpenGLib*>(gui);
    glfwDestroyWindow(openGLib->getWindow());
    glfwTerminate();
    delete openGLib;
}

}

void OpenGLib::display(std::shared_ptr<GameModel>& model) {
    int snakeLen = model->getScore() + 4;
    auto sleepTime = std::chrono::milliseconds(150 - snakeLen % 120);
    std::this_thread::sleep_for(sleepTime);

    int width, height;
    glfwGetFramebufferSize(m_window, &width, &height);
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    auto& map = *model->getMap();
    displayMap(map);
    displaySnake(model->getSnake());
    displayFood(map.getFoodBlock());

    glfwSwapBuffers(m_window);

    std::string title = windowTitle + std::to_string(model->getScore());
    glfwSetWindowTitle(m_window, title.c_str());
}

void OpenGLib::checkControls(std::shared_ptr<GameModel>& model) {
    glfwPollEvents();

    if (glfwWindowShouldClose(m_window)) {
        model->quit();
        return;
    }

    auto snake = model->getSnake();

    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(m_window, GLFW_TRUE);
    }

    if (glfwGetKey(m_window, GLFW_KEY_1)) {
        model->setLib(DisplayLibrary::SDL);
    }

    if (glfwGetKey(m_window, GLFW_KEY_2)) {
        model->setLib(DisplayLibrary::SFML);
    }

    if (glfwGetKey(m_window, GLFW_KEY_W) && snake->getDirection() != Directions::Up) {
        snake->setDirection(Directions::Up);
    }

    if (glfwGetKey(m_window, GLFW_KEY_A) && snake->getDirection() != Directions::Right) {
        snake->setDirection(Directions::Left);
    }

    if (glfwGetKey(m_window, GLFW_KEY_S) && snake->getDirection() != Directions::Up) {
        snake->setDirection(Directions::Down);
    }

    if (glfwGetKey(m_window, GLFW_KEY_D) && snake->getDirection() != Directions::Left) {
        snake->setDirection(Directions::Right);
    }
}

void OpenGLib::drawBlock(BlockPtr&& block) {
    glRectf(
        block->getX() * blockSize,
        block->getY() * blockSize,
        block->getX() * blockSize + blockSize,
        block->getY() * blockSize + blockSize
    );
}

void OpenGLib::displayMap(Map& map) {
    auto& mapBlocks = map.getMapBlocks();
    for (auto block : mapBlocks) {
        switch (block->getType()) {
            case BlockType::Surface:
                glColor3f(0.0f, 0.0f, 1.0f);
                break;
            case BlockType::Wall:
                glColor3f(1.0f, 0.0f, 0.0f);
                break;
            default:
                break;
        }
        drawBlock(std::move(block));
    }
}

void OpenGLib::displaySnake(const std::shared_ptr<Snake>& model) {
    auto snakeBlocks = model->getSnakeList();
    for (auto& block : snakeBlocks) {
        if (block->isHead()) {
            glColor3f(0.0f, 1.0f, 0.0f);
        } else {
            glColor3f(0.0f, 0.33f, 0.0f);
        }
        drawBlock(std::static_pointer_cast<Block>(block));
    }
}

void OpenGLib::displayFood(const FoodBlockPtr& foodBlock) {
    glColor3f(0.8f, 0.8f, 0.0f);
    drawBlock(std::static_pointer_cast<Block>(foodBlock));
}
