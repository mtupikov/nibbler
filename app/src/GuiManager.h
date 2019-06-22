#pragma once

#include "IGui.h"

#ifdef WIN32
#include "Win/DLLoader.h"
#else
#include "Unix/DLLoader.h"
#endif

#include <string>
#include <memory>

namespace guiLibraries {

#ifdef WIN32
const std::string sdlLibrary = "libSDLib.dll";
const std::string sfmlLibrary = "libSFMLib.dll";
#endif
#ifdef __linux__
const std::string sdlLibrary = "libSDLib.so";
const std::string sfmlLibrary = "libSFMLib.so";
#endif
#ifdef __APPLE__
const std::string sdlLibrary = "libSDLib.dylib";
const std::string sfmlLibrary = "libSFMLib.dylib";
#endif

} // end namespace guiLibraries

class GuiManager final {

public:
    GuiManager() = default;
    ~GuiManager();

    void loadGui(const std::string& lib, int width, int height);

    std::shared_ptr<IGui> getGui() const;

private:
    std::shared_ptr<IGui> m_gui;
    std::unique_ptr<dlloader::DLLoader<IGui>> m_dlloader{ nullptr };
};
