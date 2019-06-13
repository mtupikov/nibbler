#pragma once

#include "IGui.h"

#include <gtk/gtk.h>

class GTKLib : public IGui {
public:
    GTKLib() = default;
    virtual ~GTKLib() override = default;

    GtkWidget* getWindow() const;
    void setWindow(GtkWidget* window);

    void display(std::shared_ptr<GameModel>& model) override;
    void checkControls(std::shared_ptr<GameModel>& model) override;

private:
    GtkWidget* m_window{ nullptr };
};
