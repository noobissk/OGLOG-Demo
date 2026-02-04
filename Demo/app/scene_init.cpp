#include "scene_init.h"
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