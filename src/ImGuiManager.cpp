#include "ImGuiManager.h"

void ImGuiManager::DrawMainWindow(sf::RenderWindow& window)
{
	ImGui::Begin("2DE", &mainWindowShow);

	ImGui::Text("FPS: %.1f", fps);

	ImGui::Separator();

	if (ImGui::BeginTabBar("MainTabBar")) {
#pragma region Player Tab
		if (ImGui::BeginTabItem("Player")) {
			ImGui::Text("Player");
			ImGui::EndTabItem();
		}
#pragma endregion

#pragma region Settings Tab
		if (ImGui::BeginTabItem("Settings")) {

			ImGui::SliderInt("Max FPS", &maxFPS, 24, 144);
			ImGui::Checkbox("V-Sync", &vsync);

			if (ImGui::Button("Apply")) {
				window.setFramerateLimit(maxFPS);
				window.setVerticalSyncEnabled(vsync);
			}

			ImGui::EndTabItem();
		}
#pragma endregion
		ImGui::EndTabBar();
	}

	ImGui::Separator();
	if (ImGui::Button("KILL")) {
		window.close();
	}

	ImGui::End();
}
