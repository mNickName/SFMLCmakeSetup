#ifndef GameObject_HEADER
#define GameObject_HEADER

#include <SFML/Graphics.hpp>
#include <Animation.h>

class GameObject {
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    bool animate;
    Animation animation;

public:
    GameObject(const std::string& textureFile, sf::Vector2f startPosition = { 0.f, 0.f })
        : position(startPosition) {
        if (!texture.loadFromFile(textureFile)) {
            throw std::runtime_error("Failed to load texture: " + textureFile);
        }

        sprite.setTexture(texture);
        sprite.setPosition(position);
    }

    void Animate(sf::Vector2u imageCount, float switchTime = 0.2f) {
        animation = Animation(&texture, imageCount, switchTime);
        animate = true;
    }

    virtual void update(float deltaTime) {
        if (animate) {
            animation.Update(0, deltaTime);
            sprite.setTextureRect(animation.uvRect);
        }
    }

    virtual void draw(sf::RenderWindow& window) {
        sprite.setPosition(position);
        window.draw(sprite);
    }

    // Getter do bounding box (przydatny do kolizji)
    virtual sf::FloatRect getBoundingBox() const {
        return sprite.getGlobalBounds();
    }

    // Getter i setter do pozycji
    virtual sf::Vector2f getPosition() const {
        return sprite.getPosition();
    }

    virtual void setPosition(const sf::Vector2f& newPosition) {
        position = newPosition;
        sprite.setPosition(position);
    }

    virtual ~GameObject() = default;
};

#endif