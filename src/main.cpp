#include <SFML/Graphics.hpp>

#include <iostream>

#include "Animation.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(512, 512), "2DEngine", sf::Style::Close | sf::Style::Resize);

	sf::RectangleShape debug(sf::Vector2f(20.0f, 20.0f));
	debug.setPosition(256, 256);
	debug.setFillColor(sf::Color::Black);
	debug.setOutlineColor(sf::Color::White);
	debug.setOutlineThickness(2.0f);

	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	player.setPosition(256, 256);

	sf::Texture playerTexture;
	playerTexture.loadFromFile(RESOURCES_PATH "Knight/idle.png");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, sf::Vector2u(11, 0), 1.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();

		sf::Event poolEvent;
		while (window.pollEvent(poolEvent)) {
			switch (poolEvent.type) {
			case sf::Event::Closed:
				printf("\nWindow Closing");
				window.close();
				break;
			case sf::Event::Resized:
				printf("\nWindow Resized [X: %i, Y: %i]", poolEvent.size.width, poolEvent.size.height);
				break;
			case sf::Event::TextEntered:
				if (poolEvent.text.unicode > 128) break;
				printf("%c", poolEvent.text.unicode);
				break;
			}
		}

		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);

		window.clear();
		window.draw(debug);
		window.draw(player);
		window.display();
	}

	return 0;
}