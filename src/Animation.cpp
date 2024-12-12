#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	log = Logger();
	log.setClassName("Animation");

	if (imageCount.x != 0) uvRect.width = texture->getSize().x / float(imageCount.x);
	if (imageCount.y != 0) uvRect.height = texture->getSize().y / float(imageCount.y);

	texture->setSmooth(false);

	this->imageCount = imageCount;
	this->switchTime = switchTime;

	this->currentImage.x = 0;
	this->currentImage.y = 0;

	totalTime = 0.0f;
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		
		currentImage.x++;
		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;

	//log.Log("uvRect.left: " + std::to_string(uvRect.left) + "uvRect.top: " + std::to_string(uvRect.top) + "\n", Logger::Level::DEBUG);
}
