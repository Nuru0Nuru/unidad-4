#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
const unsigned


int main() {
    sf::RenderWindow App(sf::VideoMode(800, 600), "Que ventana horrible");  
    const unsigned int min = 100;
    const unsigned int max = 1000;
    const unsigned int suma = 5;

    while (App.isOpen()) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                App.close();
            }
        }      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { 
            sf::Vector2u currentSize = App.getSize();
            unsigned int newWidth = currentSize.x + suma ; 
            unsigned int newHeight = currentSize.y + suma;
            if (newWidth <= max && newHeight <= max) { 
                App.setSize(sf::Vector2u(newWidth, newHeight));
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { 
            sf::Vector2u currentSize = App.getSize();
            unsigned int newWidth = currentSize.x;
            unsigned int newHeight = currentSize.y;

            if (currentSize.x > min) {
                newWidth = currentSize.x - suma;
            }
            else {
                newWidth = min;
            }
            if (currentSize.y > min) {
                newHeight = currentSize.y - suma;
            }
            else {
                newHeight = min;
            }

            if (newWidth >= min && newHeight >= min) {
                App.setSize(sf::Vector2u(newWidth, newHeight));
            }
        }
        App.clear(sf::Color::Black);
        App.display();
    }

    return 0;
}


