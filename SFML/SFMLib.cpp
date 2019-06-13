#include <SFML/Graphics.hpp>
#include "SFMLLib.hpp"

SFMLLib::SFMLLib(int x, int y): window(sf::VideoMode(20 * x, 20 * y), "nibbler")
{
}

void	SFMLLib::display(int x, int y)
{
    sf::CircleShape		circle = sf::CircleShape(10, 50);

    this->window.clear(sf::Color::Black);

    circle.setPosition(y / 2, x / 2);
    this->window.draw(circle);
    this->window.display();
}

void	SFMLLib::close(void)
{
    this->window.clear();
    this->window.close();
}

extern "C" IGui		*init(int x, int y)
{
    return (new SFMLLib(x, y));
}

extern "C" void		close(IGui *gui)
{
    SFMLLib		*sfmllib = dynamic_cast<SFMLLib *>(gui);

    sfmllib->close();

}
