#include "GuiManager.h"

#include <iostream>
#include <dlfcn.h>

#include "Exception.h"

void GuiManager::loadGui(std::string& lib, int width, int height) {
	IGui *(*init_ptr)(int, int);

    m_dlHandle = dlopen(lib.c_str(), RTLD_GLOBAL);

    if (!m_dlHandle) {
        throw LoadGuiException(dlerror());
    }

	init_ptr = (IGui *(*)(int, int))(dlsym(m_dlHandle, "init"));

    if (!init_ptr) {
        throw FunctionAbsentException(dlerror());
    }

    m_gui = init_ptr(width, height);
}


GuiManager::~GuiManager() {
    delete m_gui;
    delete m_dlHandle;
}

IGui* GuiManager::getGui() const {
    return m_gui;
}
