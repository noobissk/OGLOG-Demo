#include "scene_system.h"
#include <iostream>

std::array<std::unique_ptr<SceneSetup>, 2> SceneController_S::scenes{{
    std::make_unique<MenuSetup>(),
    std::make_unique<GameSetup>()
}};

void SceneController_S::initialize() {
    std::cout << "[DEBUG] SceneController_S initialized." << std::endl;
    for (auto& scene_setup : scenes) {
        scene_setup->initialize();
    }
    std::cout << "[DEBUG] Initial scene loaded: " << scenes[0]->getSceneName() << std::endl;
    // SceneManager::loadScene(scenes[0]->getSceneName());
}

void SceneController_S::changeScene(int sceneID) {
    if (sceneID < 0 || sceneID >= static_cast<int>(sizeof(scenes) / sizeof(scenes[0]))) {
        std::cerr << "Invalid scene ID: " << sceneID << std::endl;
        return;
    }
    SceneManager::loadScene(scenes[sceneID]->getSceneName());
}

void SceneController_S::changeScene(const std::string& sceneName) {
    for (const auto& scene_setup : scenes) {
        if (scene_setup->getSceneName() == sceneName) {
            SceneManager::loadScene(sceneName);
            return;
        }
    }
    std::cerr << "Scene not found: " << sceneName << std::endl;
}