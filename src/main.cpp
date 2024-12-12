#include <SFML/Graphics.hpp>

#include <iostream>

#include "ImGuiManager.h"
#include "Animation.h"
#include "Objects/GameObject.cpp"
#include "Spawnables/Player.cpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "2DEngine", sf::Style::Close | sf::Style::Resize | sf::Style::Fullscreen);
	
	// Create Player Object
	Player player(RESOURCES_PATH "Knight/idle.png", sf::Vector2f(100.f, 100.f));

	//sf::RectangleShape player(sf::Vector2f(32.0f * 4, 32.0f * 4));
	//player.setPosition(256, 256);

	//Animation animation(&playerTexture, sf::Vector2u(11, 1), 0.1f);

	float deltaTime = 0.0f;
	sf::Clock clock;

#pragma region ImGui
	ImGuiManager& gui = ImGuiManager::getInstance();
	gui.initialize(window);
#pragma endregion


	while (window.isOpen()) {
		sf::Time deltaRestart = clock.restart();
		deltaTime = deltaRestart.asSeconds();

		float framesPerSecond = 1.0f / deltaTime;
		gui.fps = framesPerSecond;

		sf::Event poolEvent;
		while (window.pollEvent(poolEvent)) {
			gui.ProccessEvent(window, poolEvent);

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

		//for (auto& obj : gameObjects)
		player.update(deltaTime);
		gui.update(window, deltaRestart);

		//animation.Update(0, deltaTime);
		//player.setTextureRect(animation.uvRect);

		window.clear();

		player.draw(window);
		gui.DrawMainWindow(window);
		gui.render(window);

		window.display();
	}

	gui.shutdown();
	return 0;
}