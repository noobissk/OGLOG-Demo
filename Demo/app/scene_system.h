#pragma once

#include <string>
#include <memory>
#include <array>
#include "scenes/menu_setup.h"
#include "scenes/game_setup.h"

class SceneController_S {
public:
    static std::array<std::unique_ptr<SceneSetup>, 2> scenes;

    static void initialize();

    static void changeScene(int sceneID);
    static void changeScene(const std::string& sceneName);
};