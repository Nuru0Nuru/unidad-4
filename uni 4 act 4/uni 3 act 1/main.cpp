#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
//////Variables//////
Texture rojo;
Texture amarillo;
Sprite sprite;


int main() {
	//Cargamos la textura del archivo
	amarillo.loadFromFile("cuad_yellow.png");
	rojo.loadFromFile("rcircle.png");
	//Cargamos el material del sprite
	sprite.setTexture(amarillo);
	//Movemos el sprite
	sprite.setPosition(350, 250);
	sprite.setScale((float)100 / amarillo.getSize().x, (float)100 / amarillo.getSize().y);
	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Que ventana horrible");
	// Loop principal
	while (App.isOpen()) {

		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Space) == true) {
				sprite.setScale((float)100 / rojo.getSize().x, (float)100 / rojo.getSize().y);
				sprite.setTexture(rojo);
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right) == true) {
				if (sprite.getPosition().x + 100 < App.getSize().x) {
					sprite.move(25, 0);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Left) == true) { 
				if (sprite.getPosition().x > (0)) {
					sprite.move(-25, 0);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Up) == true) { 
				if (sprite.getPosition().y > (0)) {
					sprite.move(0, -25);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Down) == true) { 
				if (sprite.getPosition().y + 100 < App.getSize().y) {
					sprite.move(0, 25);
				}
				}
			}
			
		
		App.clear();
		// Dibujamos la escena
		App.draw(sprite);
		// Mostramos la ventana
		App.display();
	}
	return 0;
}



