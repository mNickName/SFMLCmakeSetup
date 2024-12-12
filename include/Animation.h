#include <SFML/Graphics.hpp>

#include "Logger.h"

class Animation {
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime);

public:
	sf::IntRect uvRect;

private:
	Logger log;

	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};