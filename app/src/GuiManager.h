#pragma once

#include "IGui.h"

#include <string>

class GuiManager final {

public:
    GuiManager() = default;
    virtual ~GuiManager();

    void loadGui(std::string& lib, int width, int height);

    IGui* getGui() const;

private:
    IGui* m_gui;
    void* m_dlHandle;
};
