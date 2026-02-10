#pragma once

#include "scene_setup.h"
#include <config_component.h>
#include <iostream>
#include <logic/scene_manager.h>
#include <windows.h>
#include <mmsystem.h>


#pragma comment(lib, "winmm.lib")

class MenuSetup : public SceneSetup {
public:
    MenuSetup() = default;
    ~MenuSetup() = default;

    inline void initialize() override {
        SceneManager::createScene("Menu");
        auto* scene = &SceneManager::getSceneByName("Menu");

        PlaySoundW(
            AssetManager::assetToPath(17).c_str(),
            NULL,
            SND_FILENAME | SND_ASYNC | SND_LOOP
        );

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
        auto& char_ui = scene->addComponent<UIElement_C>(char_e, UIElement_C(glm::vec2(960.0f, 540.0f), glm::vec2(2080.0f, 1080.0f)));
        char_ui.canvas = canvas_e;
        auto& char_paralax = scene->addComponent<Paralax_C>(char_e, Paralax_C(glm::vec3(0.05f, 0.01f, 0.0f)));

        Entity button_play_e = scene->createEntity();
        auto& button_play_transform = scene->addComponent<Transform_C>(button_play_e, Transform_C(button_play_e));
        auto& button_play_renderer = scene->addComponent<MeshRenderer_C>(button_play_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 8)));
        auto& button_play_button = scene->addComponent<Button_C>(button_play_e, Button_C(([] () {
            std::cout << "[LOG] Play button clicked!" << std::endl;
            SceneManager::loadScene("Game");
        })));
        auto& button_play_ui = scene->addComponent<UIElement_C>(button_play_e, UIElement_C(glm::vec2(960.0f, 540.0f), glm::vec2(400.0f, 150.0f)));
        button_play_ui.canvas = canvas_e;

        Entity text_button_play_e = scene->createEntity();
        auto& text_button_play_transform = scene->addComponent<Transform_C>(text_button_play_e, Transform_C(text_button_play_e));
        auto& text_button_play_renderer = scene->addComponent<MeshRenderer_C>(text_button_play_e, MeshRenderer_C(std::make_shared<MaterialFont>(ShaderManager::get("font"), 20, std::vector<Asset>{14, 15, 18, 19})));
        auto mat_font = std::dynamic_pointer_cast<MaterialFont>(text_button_play_renderer.material);
        auto& text_button_play_text = scene->addComponent<Text_C>(text_button_play_e, Text_C(text_button_play_e, mat_font->font));
        text_button_play_text.text = "Play";
        text_button_play_text.text_size = 20;
        text_button_play_text.color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        text_button_play_text.alignment = TextAlign::CENTER;
        text_button_play_text.v_alignment = VerticalAlign::CENTER;
        auto& text_button_play_ui = scene->addComponent<UIElement_C>(text_button_play_e, UIElement_C(glm::vec2(880.0f, 540.0f), glm::vec2(400.0f)));
        text_button_play_ui.canvas = canvas_e;
        text_button_play_ui.apply_scaling = false;
        text_button_play_ui.anchor = glm::vec2(0.5f, 0.5f);


        Entity button_exit_e = scene->createEntity();
        auto& button_exit_transform = scene->addComponent<Transform_C>(button_exit_e, Transform_C(button_exit_e));
        auto& button_exit_renderer = scene->addComponent<MeshRenderer_C>(button_exit_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 8)));
        auto& button_exit_button = scene->addComponent<Button_C>(button_exit_e, Button_C(([] () {
            std::cout << "[LOG] Exit button clicked!" << std::endl;
            std::exit(0);
        })));
        auto& button_exit_ui = scene->addComponent<UIElement_C>(button_exit_e, UIElement_C(glm::vec2(960.0f, 760.0f), glm::vec2(400.0f, 150.0f)));
        button_exit_ui.canvas = canvas_e;
        Entity text_button_exit_e = scene->createEntity();

        auto& text_button_exit_transform = scene->addComponent<Transform_C>(text_button_exit_e, Transform_C(text_button_exit_e));
        auto& text_button_exit_renderer = scene->addComponent<MeshRenderer_C>(text_button_exit_e, MeshRenderer_C(std::make_shared<MaterialFont>(ShaderManager::get("font"), 20, std::vector<Asset>{14, 33, 18, 19})));
        auto mat_font_exit = std::dynamic_pointer_cast<MaterialFont>(text_button_exit_renderer.material);
        auto& text_button_exit_text = scene->addComponent<Text_C>(text_button_exit_e, Text_C(text_button_exit_e, mat_font_exit->font));
        text_button_exit_text.text = "Exit";
        text_button_exit_text.text_size = 20;
        text_button_exit_text.color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        text_button_exit_text.alignment = TextAlign::CENTER;
        text_button_exit_text.v_alignment = VerticalAlign::CENTER;
        auto& text_button_exit_ui = scene->addComponent<UIElement_C>(text_button_exit_e, UIElement_C(glm::vec2(880.0f, 760.0f), glm::vec2(400.0f)));
        text_button_exit_ui.canvas = canvas_e;
        text_button_exit_ui.apply_scaling = false;
        text_button_exit_ui.anchor = glm::vec2(0.5f, 0.5f);

    }

    inline std::string getSceneName() const override {
        return "Menu";
    }
};
