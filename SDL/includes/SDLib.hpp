# include <SDL.h>
# include <iostream>
#include "IGui.hpp"
#include "GameModel.hpp"

class SDLib: public IGui
{

public:
    SDLib();
    virtual ~SDLib(void);

    SDL_Window	    *getWindow() const;
	SDL_Surface		*getScreen() const;

	void			setScreen(SDL_Surface	*screen);
    void			setWindow(SDL_Window	*window);
    void			display(GameModel *model) override;
	void 			checkControls(GameModel *model) override;
    void			close();

private:
	void 			displayMap(Map &map, int blockSize);
	void			displaySnake(GameModel *model, int blockSize);
	void			displayFood(Map &map, int blockSize);
    SDL_Window	    *_window;
    SDL_Surface    	*_screen;
	SDL_Event		_event;
};
