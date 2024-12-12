#include "../Objects/GameObject.cpp"

class Player : GameObject {
public:
    Player(const std::string& textureFile, sf::Vector2f startPosition = { 0.f, 0.f })
        : GameObject(textureFile, startPosition) {}

    // Aktualizacja logiki gracza
    void update(float deltaTime) override {

    }

    void draw(sf::RenderWindow& window) override {
        GameObject::draw(window);
    }
};