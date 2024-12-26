#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> 
using namespace sf; 

const int ancho = 800;
const int alto = 600;
const int max = 5;

class Mira {
private:
    Sprite sprite;
    Texture texture;

public:
    Mira(const std::string& texturePath) {
        texture.loadFromFile(texturePath);
        sprite.setTexture(texture);
        sprite.setScale(0.8f, 0.8f); 
        sprite.setOrigin(sprite.getScale().x * texture.getSize().x / 2.0f, sprite.getScale().y * texture.getSize().y / 2.0f);
    }

    void Actualizar(sf::RenderWindow& window) {
        Vector2i puntero = sf::Mouse::getPosition(window);
        sprite.setPosition(static_cast<float>(puntero.x), static_cast<float>(puntero.y));
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }
};

class Et {
private:
    Sprite sprite;
    Texture texture;

public:
    Et(const std::string& texturePath) {
        texture.loadFromFile(texturePath);
        sprite.setTexture(texture);
        sprite.setScale(0.05f, 0.05f);
        Show();
    }

    void Show() {
        float x = static_cast<float>(rand() % (ancho - static_cast<int>(sprite.getGlobalBounds().width)));
        float y = static_cast<float>(rand() % (alto - static_cast<int>(sprite.getGlobalBounds().height)));
        sprite.setPosition(x, y);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }
};

int main() {
    
    sf::RenderWindow App(sf::VideoMode(ancho, alto), "Que ventana horrible");
    srand(static_cast<unsigned>(time(0)));
        Mira mira("crosshair.png");  
        Et et("et.png");

    int defeatedEnemies = 0;
    
    while (App.isOpen()) {

        sf::Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                App.close();

            if (evt.type == sf::Event::MouseButtonPressed && evt.mouseButton.button == sf::Mouse::Left) {
                if (et.getBounds().contains(static_cast<float>(sf::Mouse::getPosition(App).x),
                    static_cast<float>(sf::Mouse::getPosition(App).y))) {
                    defeatedEnemies++;
                    if (defeatedEnemies >= max) {
                        App.close();
                    }
                    else {
                        et.Show();
                    }
                }
            }
        }

        mira.Actualizar(App);    
        App.clear();
        et.draw(App);
        mira.draw(App);
        App.display(); 
    }

    return 0;
}