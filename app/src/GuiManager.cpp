#include "GuiManager.h"

#include <iostream>
#ifndef WIN32
#include <dlfcn.h>
#else
#include <Windows.h>
#endif

#include "Exception.h"

void GuiManager::loadGui(std::string& lib, int width, int height) {
	IGui *(*init_ptr)(int, int);

#ifndef WIN32
    m_dlHandle = dlopen(lib.c_str(), RTLD_GLOBAL);

    if (!m_dlHandle) {
        throw LoadGuiException(dlerror());
    }

    init_ptr = (IGui *(*)(int, int))(dlsym(m_dlHandle, "init"));

    if (!init_ptr) {
        throw FunctionAbsentException(dlerror());
    }
#else
    m_dlHandle = LoadLibrary(lib.c_str());

    if (!m_dlHandle) {
        throw LoadGuiException("Cannot load library");
    }

    init_ptr = (IGui *(*)(int, int))GetProcAddress(static_cast<HINSTANCE>(m_dlHandle), "init");

    if (!init_ptr) {
        throw FunctionAbsentException("Init function is absent");
    }
#endif





    m_gui = init_ptr(width, height);
}


GuiManager::~GuiManager() {
    delete m_gui;

#ifndef WIN32
    dlclose(m_dlHandle);
#else
    FreeLibrary(static_cast<HINSTANCE>(m_dlHandle));
#endif
}

IGui* GuiManager::getGui() const {
    return m_gui;
}
