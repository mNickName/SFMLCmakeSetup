#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"
#include <imguiThemes.h>

class ImGuiManager {
public:
    static ImGuiManager& getInstance() {
        static ImGuiManager instance;
        return instance;
    }

    void DrawMainWindow(sf::RenderWindow& window);

    void ToggleWindow() {
        mainWindowShow = !mainWindowShow;
    }

    void initialize(sf::RenderWindow& window) {
        ImGui::SFML::Init(window, false);
        
        imguiThemes::green();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.Fonts->Clear();
        io.Fonts->AddFontFromFileTTF(RESOURCES_PATH "fonts/imgui_regular.ttf", 24.f);
        io.FontAllowUserScaling = true;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiWindowFlags_NoBackground;
        io.FontGlobalScale = 0.8f;

        ImGui::SFML::UpdateFontTexture();

        ImGuiStyle& style = ImGui::GetStyle();
        style.AntiAliasedFill = true;
        style.AntiAliasedLines = true;
        style.AntiAliasedLinesUseTex = true;
        
        style.Colors[ImGuiCol_WindowBg].w = 0.f;
    }

    void render(sf::RenderWindow& window) {
        ImGui::SFML::Render(window);
    }

    void update(sf::RenderWindow& window, sf::Time deltaTime) {
        ImGui::SFML::Update(window, deltaTime);
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
    }

    void ProccessEvent(sf::RenderWindow& window, sf::Event event) {
        ImGui::SFML::ProcessEvent(window, event);
    }

    void shutdown() {
        ImGui::SFML::Shutdown();
    }

public:
    float fps = 0.0f;

private:
    int maxFPS = 144;
    bool vsync = true;
    bool mainWindowShow = true;

private:
    ImGuiManager() = default;
    ~ImGuiManager() = default;

    ImGuiManager(const ImGuiManager&) = delete;
    ImGuiManager& operator=(const ImGuiManager&) = delete;
};
