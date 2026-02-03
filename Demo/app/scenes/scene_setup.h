#pragma once
#include <logic/scene_manager.h>

class SceneSetup {
public:
    SceneSetup() = default;
    ~SceneSetup() = default;

    virtual void initialize() = 0;
    virtual std::string getSceneName() const = 0;
};