#include "GTKLib.hpp"

GTKLib::GTKLib(): window(NULL)
{
}

GTKLib::~GTKLib()
{
}

GtkWidget	*GTKLib::getWindow() const
{
    return (this->window);
}

void			GTKLib::setWindow(GtkWidget *window)
{
    this->window = window;
}

extern "C" IGui		*init(int x, int y)
{
    char    **argv;
    int     argc = 0;
    GTKLib	*gui = new GTKLib();
    x = y;
    gtk_init (&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "nibbler");
    gtk_window_set_default_size (GTK_WINDOW (window), x, y);
    gtk_container_set_border_width (GTK_CONTAINER(window), 50);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_container_border_width (GTK_CONTAINER (window), 10);
    gui->setWindow(window);
    return (gui);

}

extern "C" void		closer(IGui *gui)
{

    gui = nullptr;
    //GTKLib		*gtkgui = dynamic_cast<GTKLib *>(gui);

    //delete gtkgui;
}

void		GTKLib::display(int x, int y)
{
    x = y;
    gtk_widget_show(window);

    gtk_main();
}

