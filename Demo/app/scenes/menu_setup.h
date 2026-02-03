#pragma once

#include "scene_setup.h"
#include <config_component.h>
#include <iostream>

class MenuSetup : public SceneSetup {
public:
    MenuSetup() = default;
    ~MenuSetup() = default;

    inline void initialize() override {
        SceneManager::createScene("Menu");
        auto* scene = &SceneManager::getSceneByName("Menu");

        Entity canvas_e = scene->createEntity();
        auto& canvas_transform = scene->addComponent<Transform_C>(canvas_e, Transform_C(canvas_e));
        auto& canvas_canvas = scene->addComponent<Canvas_C>(canvas_e, Canvas_C());

        Entity wall_e = scene->createEntity();
        auto& wall_transform = scene->addComponent<Transform_C>(wall_e, Transform_C(wall_e));
        auto& wall_renderer = scene->addComponent<MeshRenderer_C>(wall_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 2)));
        auto& wall_ui = scene->addComponent<UIElement_C>(wall_e, UIElement_C(glm::vec2(960.0f, 540.0f), glm::vec2(1920.0f, 1080.0f)));
        wall_ui.canvas = canvas_e;
        
        Entity char_e = scene->createEntity();
        auto& char_transform = scene->addComponent<Transform_C>(char_e, Transform_C(char_e));
        auto& char_renderer = scene->addComponent<MeshRenderer_C>(char_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 1)));
        auto& char_ui = scene->addComponent<UIElement_C>(char_e, UIElement_C(glm::vec2(1040.0f, 540.0f), glm::vec2(2080.0f, 1080.0f)));
        char_ui.canvas = canvas_e;

    }

    inline std::string getSceneName() const override {
        return "Menu";
    }
};
