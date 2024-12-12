#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"
#include <imguiThemes.h>

class ImGuiManager {
public:
    //explicit ImGuiManager();
    //~ImGuiManager();

    // Pobieranie instancji Singletona
    static ImGuiManager& getInstance() {
        static ImGuiManager instance;
        return instance;
    }

    void DrawMainWindow(sf::RenderWindow& window);

    // Funkcja inicjalizacji ImGui
    void initialize(sf::RenderWindow& window) {
        ImGui::SFML::Init(window);
        imguiThemes::green();

        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.FontGlobalScale = 2.f;

        ImGuiStyle& style = ImGui::GetStyle();
        style.Colors[ImGuiCol_WindowBg].w = 0.5f;
    }

    // Funkcja obs³ugi ImGui
    void render(sf::RenderWindow& window) {
        ImGui::SFML::Render(window);
    }

    // Aktualizacja logiki ImGui
    void update(sf::RenderWindow& window, sf::Time deltaTime) {
        ImGui::SFML::Update(window, deltaTime);
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
    }

    void ProccessEvent(sf::RenderWindow& window, sf::Event event) {
        ImGui::SFML::ProcessEvent(window, event);
    }

    // Zakoñczenie ImGui
    void shutdown() {
        ImGui::SFML::Shutdown();
    }

public:
    float fps = 0.0f;

private:
    int maxFPS = 144;
    bool vsync = true;

private:
    ImGuiManager() = default; // Konstruktor prywatny
    ~ImGuiManager() = default;

    ImGuiManager(const ImGuiManager&) = delete;
    ImGuiManager& operator=(const ImGuiManager&) = delete;
};
