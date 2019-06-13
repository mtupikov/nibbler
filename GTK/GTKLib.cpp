#include "GTKLib.h"

#include "GameModel.h"

#include <iostream>

GtkWidget* GTKLib::getWindow() const {
    return m_window;
}

void GTKLib::setWindow(GtkWidget *window)
{
    m_window = window;
}

extern "C" {

IGui* allocator(int x, int y) {
    char** argv;
    int argc = 0;

    auto gui = new GTKLib();
    gtk_init(&argc, &argv);

    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "nibbler");
    gtk_window_set_default_size(GTK_WINDOW(window), x, y);
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_border_width(GTK_CONTAINER(window), 10);
    gui->setWindow(window);

    return gui;
}

void deleter(IGui* gui) {
    auto gtkGui = dynamic_cast<GTKLib*>(gui);
    delete gtkGui;
}

}

void GTKLib::display(std::shared_ptr<GameModel>& model) {

}

void GTKLib::checkControls(std::shared_ptr<GameModel>& model) {

}


