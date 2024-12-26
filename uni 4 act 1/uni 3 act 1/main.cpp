#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
//////Variables//////
Texture hair;
Sprite cross;

int main() {
	//Cargamos la textura del archivo
	hair.loadFromFile("crosshair.png");
	//Cargamos el material del sprite
	cross.setTexture(hair);
	//Movemos el sprite
	cross.setPosition(336, 236);
	//Creamos la ventana
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Que ventana horrible");
	// Loop principal
	while (App.isOpen()) {
		// Limpiamos la ventana
		App.clear();
		// Dibujamos la escena
		App.draw(cross);
		// Mostramos la ventana
		App.display();
	}
	return 0;
}



