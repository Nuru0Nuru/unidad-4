#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

const int ventanaW = 800;
const int ventanaH = 600;
const int Enemigos = 5;

class  mira {
private:
	Sprite sprite;
	Texture texture;
public: 
	mira(const std::string& texturePath) {
		texture.loadFromFile(texturePath);
		sprite.setTexture(texture);
		sprite.setScale(0.8f, 0.8f);
		sprite.setOrigin(sprite.getScale().x * texture.getSize().x / 2.0f, sprite.getScale().y * texture.getSize().y / 2.0f);
	}
	void actualizar(sf::RenderWindow& window) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sprite.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	sf::FloatRect getBounds()const {
		return sprite.getGlobalBounds();
	}
};

class  et { 
private:
	Sprite sprite;
	Texture texture;
public:
	et(const std::string& texturePath) {
		texture.loadFromFile(texturePath);
		sprite.setTexture(texture);
		sprite.setScale(0.05f, 0.05f);
		respawn(); 
	}
	void respawn() {
		float x = static_cast<float>(rand() % (ventanaW - static_cast<int>(sprite.getGlobalBounds().width)));
		float y = static_cast<float>(rand() % (ventanaH - static_cast<int>(sprite.getGlobalBounds().height)));
		sprite.setPosition(x, y);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	sf::FloatRect getBounds()const {
		return sprite.getGlobalBounds();
	}
};

int main() {
	
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),"Que ventana horrible");
	App.setFramerateLimit(60);
	srand(static_cast<unsigned>(time(0)));
	mira Mira("crosshair.png"); 
	et Et("et.png"); 

	int contador = 0;
	while (App.isOpen()) {
		Event evt;
		while (App.pollEvent(evt)) {
			if (evt.type == Event::Closed) {
				App.close();
			}

			if (evt.type == sf::Event::MouseButtonPressed && evt.mouseButton.button == sf::Mouse::Left) {
				if (Et.getBounds().contains(static_cast<float>(sf::Mouse::getPosition(App).x), static_cast<float>(sf::Mouse::getPosition(App).y))){
					contador++;
					if (contador >= Enemigos) {
						App.close();
					}
					else {
						Et.respawn();
					}
				}
			}
		}
		Mira.actualizar(App);
		App.clear();
		Et.draw(App);
		Mira.draw(App);
		App.display();
	}
	
	return 0;
}



