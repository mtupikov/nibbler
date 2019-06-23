#include "GuiManager.h"

#include <iostream>
#ifndef WIN32
#include <dlfcn.h>
#else
#include <Windows.h>
#endif

#include "Exception.h"

void GuiManager::loadGui(const std::string& lib, int width, int height) {
    m_gui.reset();
    if (m_dlloader) {
        m_dlloader->closeLibrary();
    }

    m_dlloader = std::make_unique<dlloader::DLLoader<IGui>>(lib);

    if (!m_dlloader->openLibrary()) {
        throw LoadGuiException("Cannot load library");
    }

    m_gui = m_dlloader->getInstance(width, height);

    if (!m_gui) {
        throw FunctionAbsentException("Init function is absent");
    }
}

GuiManager::~GuiManager() {
    m_gui.reset();
    if (m_dlloader) {
        m_dlloader->closeLibrary();
    }
}

std::shared_ptr<IGui> GuiManager::getGui() const {
    return m_gui;
}
