#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture rojo;
Sprite p1;
Sprite p2;
Sprite p3;
Sprite p4;
bool bandera = false;
bool bandera2 = false;
bool bandera3 = false;
bool bandera4 = false;


int main() {
	sf::Event evt;
	
	rojo.loadFromFile("rcircle.png");
	p1.setTexture(rojo);
	p2.setTexture(rojo);
	p3.setTexture(rojo);
	p4.setTexture(rojo);
	//Movemos el sprite
	p1.setPosition(0, 0);
	p2.setPosition(0, 472);
	p3.setPosition(672, 0);
	p4.setPosition(672, 472);
	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Que ventana horrible");
	// Loop principal
	while (App.isOpen()) {
		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type) {
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			}

			if (Mouse::isButtonPressed(Mouse::Left)) { //bandera 1
			sf:Vector2i windowPosition = sf::Mouse::getPosition(App);
				float sizex = rojo.getSize().x;
				float sizey = rojo.getSize().y;
				float posx = p1.getPosition().x;
				float posy = p1.getPosition().y;
				int mousex = windowPosition.x;
				int mousey = windowPosition.y;

				if ((mousex >= posx) && (mousex <= (posx + sizex))) {
					if ((mousey >= posy) && (mousey <= (posy + sizey))) {
						bandera = true;
					}
				}
			}
			else {
				bandera = false;
			}

			if (bandera == true) {
				sf::Vector2i windowPosition = sf::Mouse::getPosition(App);
				p1.setPosition(windowPosition.x, windowPosition.y);
			}

			if (Mouse::isButtonPressed(Mouse::Left)) { //bandera 2
			sf::Vector2i windowPosition = sf::Mouse::getPosition(App);
				float sizex = rojo.getSize().x;
				float sizey = rojo.getSize().y;
				float posx = p2.getPosition().x;
				float posy = p2.getPosition().y;
				int mousex = windowPosition.x;
				int mousey = windowPosition.y;

				if ((mousex >= posx) && (mousex <= (posx + sizex))) {
					if ((mousey >= posy) && (mousey <= (posy + sizey))) {
						bandera2 = true;
					}
				}
			}
			else {
				bandera2 = false;
			}

			if (bandera2 == true) {
				sf::Vector2i windowPosition = sf::Mouse::getPosition(App);
				p2.setPosition(windowPosition.x, windowPosition.y);
			}

			if (Mouse::isButtonPressed(Mouse::Left)) { //bandera 3
			sf::Vector2i windowPosition = sf::Mouse::getPosition(App);
				float sizex = rojo.getSize().x;
				float sizey = rojo.getSize().y;
				float posx = p3.getPosition().x;
				float posy = p3.getPosition().y;
				int mousex = windowPosition.x;
				int mousey = windowPosition.y;

				if ((mousex >= posx) && (mousex <= (posx + sizex))) {
					if ((mousey >= posy) && (mousey <= (posy + sizey))) {
						bandera3 = true;
					}
				}
			}
			else {
				bandera3 = false;
			}

			if (bandera3 == true) {
				sf::Vector2i windowPosition = sf::Mouse::getPosition(App);
				p3.setPosition(windowPosition.x, windowPosition.y);
			}



			if (Mouse::isButtonPressed(Mouse::Left)) { //bandera 4
			sf::Vector2i windowPosition = sf::Mouse::getPosition(App);
				float sizex = rojo.getSize().x;
				float sizey = rojo.getSize().y;
				float posx = p4.getPosition().x;
				float posy = p4.getPosition().y;
				int mousex = windowPosition.x;
				int mousey = windowPosition.y;

				if ((mousex >= posx) && (mousex <= (posx + sizex))) {
					if ((mousey >= posy) && (mousey <= (posy + sizey))) {
						bandera4 = true;
					}
				}
			}
			else {
				bandera4 = false;
			}

			if (bandera4 == true) {
				sf::Vector2i windowPosition = sf::Mouse::getPosition(App);
				p4.setPosition(windowPosition.x, windowPosition.y);
			}

			// Limpiamos la ventana
			App.clear();
			// Dibujamos la escena
			App.draw(p1);
			App.draw(p2);
			App.draw(p3);
			App.draw(p4);
			// Mostramos la ventana
			App.display();
		}
	}
	return 0;
}



