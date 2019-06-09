
# include <gtk/gtk.h>
# include <iostream>
# include "IGui.hpp"

class GTKLib : public IGui
{

public:
    GTKLib();
    virtual ~GTKLib(void);



    GtkWidget	    *getWindow(void) const;

    void			setWindow(GtkWidget *window);

    void	        display(int x, int y);

private:

    GtkWidget *window;
};
