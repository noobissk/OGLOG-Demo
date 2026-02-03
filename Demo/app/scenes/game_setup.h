#pragma once

#include "scene_setup.h"

class GameSetup : public SceneSetup {
public:
    GameSetup() = default;
    ~GameSetup() = default;

    inline void initialize() override {
        SceneManager::createScene("Game");
        
    }

    inline std::string getSceneName() const override {
        return "Game";
    }
};