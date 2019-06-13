#pragma once

#include <SFML/Window.hpp>
#include "../../includes/IGui.hpp"


class SFMLLib: public IGui {

public:
    SFMLLib(int x, int y);
    ~SFMLLib();

    void	display(int x, int y);

    void	close();

	IGui		*init(int x, int y);

private:
    sf::RenderWindow	window;
};
