#pragma once

#include "scene_setup.h"
#include <config_component.h>
#include <iostream>
#include <logic/scene_manager.h>

class GameSetup : public SceneSetup {
    inline void moodToRenderer(Mood_C* mood, int btn, MeshRenderer_C* happy_renderer, MeshRenderer_C* sad_renderer, MeshRenderer_C* angry_renderer) {
        switch (mood->mood) { // btns -> gift, talk, work
            case Mood_C::Mood::HAPPY:
                if (btn == 0) {
                    mood->mood = Mood_C::Mood::ANGRY;
                    happy_renderer->is_enabled = false;
                    angry_renderer->is_enabled = true;
                    std::cout << "Mood changed to ANGRY" << std::endl;
                    std::cout << "Happy renderer enabled: " << happy_renderer->is_enabled << std::endl;
                    std::cout << "Angry renderer enabled: " << angry_renderer->is_enabled << std::endl;
                } else if (btn == 2) {
                    mood->mood = Mood_C::Mood::SAD;
                    happy_renderer->is_enabled = false;
                    sad_renderer->is_enabled = true;
                }
                break;
            case Mood_C::Mood::SAD:
                if (btn == 0) {
                    mood->mood = Mood_C::Mood::ANGRY;
                    angry_renderer->is_enabled = true;
                    sad_renderer->is_enabled = false;
                } else if (btn == 1) {
                    mood->mood = Mood_C::Mood::HAPPY;
                    happy_renderer->is_enabled = true;
                    sad_renderer->is_enabled = false;
                }
                break;
            case Mood_C::Mood::ANGRY:
                if (btn == 0) {
                    mood->mood = Mood_C::Mood::HAPPY;
                    happy_renderer->is_enabled = true;
                    angry_renderer->is_enabled = false;
                } else if (btn == 2) {
                    mood->mood = Mood_C::Mood::SAD;
                    angry_renderer->is_enabled = false;
                    sad_renderer->is_enabled = true;
                }
                break;
        }
    }
public:
    GameSetup() = default;
    ~GameSetup() = default;

    inline void initialize() override {
        SceneManager::createScene("Game");
        auto* scene = &SceneManager::getSceneByName("Game");

        Entity mood_e = scene->createEntity();
        auto& mood_mood = scene->addComponent<Mood_C>(mood_e, Mood_C());
        
        Entity canvas_e = scene->createEntity();
        auto& canvas_transform = scene->addComponent<Transform_C>(canvas_e, Transform_C(canvas_e));
        auto& canvas_canvas = scene->addComponent<Canvas_C>(canvas_e, Canvas_C());

        Entity morning_e = scene->createEntity();
        auto& morning_transform = scene->addComponent<Transform_C>(morning_e, Transform_C(morning_e));
        auto& morning_renderer = scene->addComponent<MeshRenderer_C>(morning_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 5)));
        auto& morning_ui = scene->addComponent<UIElement_C>(morning_e, UIElement_C(glm::vec2(960.0f, 540.0f), glm::vec2(1920.0f*1.04f, 1080.0f*1.05f)));
        morning_ui.canvas = canvas_e;
        auto& morning_paralax = scene->addComponent<Paralax_C>(morning_e, Paralax_C(glm::vec3(0.05f, 0.01f, 0.0f)));

        Entity evening_e = scene->createEntity();
        auto& evening_transform = scene->addComponent<Transform_C>(evening_e, Transform_C(evening_e));
        auto& evening_renderer = scene->addComponent<MeshRenderer_C>(evening_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 3)));
        auto& evening_ui = scene->addComponent<UIElement_C>(evening_e, UIElement_C(glm::vec2(960.0f, 540.0f), glm::vec2(1920.0f*1.04f, 1080.0f*1.05f)));
        evening_ui.canvas = canvas_e;
        auto& evening_paralax = scene->addComponent<Paralax_C>(evening_e, Paralax_C(glm::vec3(0.05f, 0.01f, 0.0f)));
        evening_renderer.is_enabled = false;

        Entity night_e = scene->createEntity();
        auto& night_transform = scene->addComponent<Transform_C>(night_e, Transform_C(night_e));
        auto& night_renderer = scene->addComponent<MeshRenderer_C>(night_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 6)));
        auto& night_ui = scene->addComponent<UIElement_C>(night_e, UIElement_C(glm::vec2(960.0f, 540.0f), glm::vec2(1920.0f*1.04f, 1080.0f*1.05f)));
        night_ui.canvas = canvas_e;
        auto& night_paralax = scene->addComponent<Paralax_C>(night_e, Paralax_C(glm::vec3(0.05f, 0.01f, 0.0f)));
        night_renderer.is_enabled = false;


        Entity happy_e = scene->createEntity();
        auto& happy_transform = scene->addComponent<Transform_C>(happy_e, Transform_C(happy_e));
        auto& happy_renderer = scene->addComponent<MeshRenderer_C>(happy_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 9)));
        auto& happy_ui = scene->addComponent<UIElement_C>(happy_e, UIElement_C(glm::vec2(1040.0f, 540.0f), glm::vec2(2080.0f, 1080.0f)));
        happy_ui.canvas = canvas_e;
        happy_renderer.is_enabled = false;
        
        Entity sad_e = scene->createEntity();
        auto& sad_transform = scene->addComponent<Transform_C>(sad_e, Transform_C(sad_e));
        auto& sad_renderer = scene->addComponent<MeshRenderer_C>(sad_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 12)));
        auto& sad_ui = scene->addComponent<UIElement_C>(sad_e, UIElement_C(glm::vec2(1040.0f, 540.0f), glm::vec2(2080.0f, 1080.0f)));
        sad_ui.canvas = canvas_e;
        sad_renderer.is_enabled = false;

        Entity angry_e = scene->createEntity();
        auto& angry_transform = scene->addComponent<Transform_C>(angry_e, Transform_C(angry_e));
        auto& angry_renderer = scene->addComponent<MeshRenderer_C>(angry_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 13)));
        auto& angry_ui = scene->addComponent<UIElement_C>(angry_e, UIElement_C(glm::vec2(1040.0f, 540.0f), glm::vec2(2080.0f, 1080.0f)));
        angry_ui.canvas = canvas_e;
        angry_renderer.is_enabled = false;

        std::cout << "happy_entity: " << happy_e << ", sad_entity: " << sad_e << std::endl;

        happy_renderer.is_enabled = false;
        sad_renderer.is_enabled = false;
        // angry_renderer.is_enabled = false;


        Entity button_back_e = scene->createEntity();
        auto& button_back_transform = scene->addComponent<Transform_C>(button_back_e, Transform_C(button_back_e));
        auto& button_back_renderer = scene->addComponent<MeshRenderer_C>(button_back_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 8)));
        auto& button_back_button = scene->addComponent<Button_C>(button_back_e, Button_C(([] () {
            std::cout << "[LOG] Back button clicked!" << std::endl;
            SceneManager::loadScene("Menu");
        })));
        auto& button_back_ui = scene->addComponent<UIElement_C>(button_back_e, UIElement_C(glm::vec2(1410.0f, 940.0f), glm::vec2(200.0f, 75.0f)));
        button_back_ui.canvas = canvas_e;

        Entity text_button_back_e = scene->createEntity();
        auto& text_button_back_transform = scene->addComponent<Transform_C>(text_button_back_e, Transform_C(text_button_back_e));
        auto& text_button_back_renderer = scene->addComponent<MeshRenderer_C>(text_button_back_e, MeshRenderer_C(std::make_shared<MaterialFont>(ShaderManager::get("font"), 20, std::vector<Asset>{14, 15, 18, 19})));
        auto mat_font_1 = std::dynamic_pointer_cast<MaterialFont>(text_button_back_renderer.material);
        auto& text_button_back_text = scene->addComponent<Text_C>(text_button_back_e, Text_C(text_button_back_e, mat_font_1->font));
        text_button_back_text.text = "Back";
        text_button_back_text.text_size = 10;
        text_button_back_text.color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        text_button_back_text.alignment = TextAlign::CENTER;
        text_button_back_text.v_alignment = VerticalAlign::CENTER;
        auto& text_button_back_ui = scene->addComponent<UIElement_C>(text_button_back_e, UIElement_C(glm::vec2(1365.0f, 940.0f), glm::vec2(400.0f)));
        text_button_back_ui.canvas = canvas_e;
        text_button_back_ui.apply_scaling = false;
        text_button_back_ui.anchor = glm::vec2(0.5f, 0.5f);


        Entity button_gift_e = scene->createEntity();
        auto& button_gift_transform = scene->addComponent<Transform_C>(button_gift_e, Transform_C(button_gift_e));
        auto& button_gift_renderer = scene->addComponent<MeshRenderer_C>(button_gift_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 8)));
        auto& button_gift_button = scene->addComponent<Button_C>(button_gift_e, Button_C(([this, scene, happy_e, sad_e, angry_e, mood_e] () {
            auto* mood = &scene->getComponent<Mood_C>(mood_e);
            auto* happy_renderer = &scene->getComponent<MeshRenderer_C>(happy_e);
            auto* sad_renderer   = &scene->getComponent<MeshRenderer_C>(sad_e);
            auto* angry_renderer = &scene->getComponent<MeshRenderer_C>(angry_e);

            moodToRenderer(mood, 0, happy_renderer, sad_renderer, angry_renderer);
        })));
        auto& button_gift_ui = scene->addComponent<UIElement_C>(button_gift_e, UIElement_C(glm::vec2(1110.0f, 940.0f), glm::vec2(200.0f, 75.0f)));
        button_gift_ui.canvas = canvas_e;

        Entity text_button_gift_e = scene->createEntity();
        auto& text_button_gift_transform = scene->addComponent<Transform_C>(text_button_gift_e, Transform_C(text_button_gift_e));
        auto& text_button_gift_renderer = scene->addComponent<MeshRenderer_C>(text_button_gift_e, MeshRenderer_C(std::make_shared<MaterialFont>(ShaderManager::get("font"), 20, std::vector<Asset>{14, 15, 18, 19})));
        auto mat_font_2 = std::dynamic_pointer_cast<MaterialFont>(text_button_gift_renderer.material);
        auto& text_button_gift_text = scene->addComponent<Text_C>(text_button_gift_e, Text_C(text_button_gift_e, mat_font_2->font));
        text_button_gift_text.text = "Gift";
        text_button_gift_text.text_size = 10;
        text_button_gift_text.color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        text_button_gift_text.alignment = TextAlign::CENTER;
        text_button_gift_text.v_alignment = VerticalAlign::CENTER;
        auto& text_button_gift_ui = scene->addComponent<UIElement_C>(text_button_gift_e, UIElement_C(glm::vec2(1065.0f, 940.0f), glm::vec2(400.0f)));
        text_button_gift_ui.canvas = canvas_e;
        text_button_gift_ui.apply_scaling = false;
        text_button_gift_ui.anchor = glm::vec2(0.5f, 0.5f);


        Entity button_talk_e = scene->createEntity();
        auto& button_talk_transform = scene->addComponent<Transform_C>(button_talk_e, Transform_C(button_talk_e));
        auto& button_talk_renderer = scene->addComponent<MeshRenderer_C>(button_talk_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 8)));
        auto& button_talk_button = scene->addComponent<Button_C>(button_talk_e, Button_C(([this, scene, happy_e, sad_e, angry_e, mood_e] () {
            auto* mood = &scene->getComponent<Mood_C>(mood_e);
            auto* happy_renderer = &scene->getComponent<MeshRenderer_C>(happy_e);
            auto* sad_renderer   = &scene->getComponent<MeshRenderer_C>(sad_e);
            auto* angry_renderer = &scene->getComponent<MeshRenderer_C>(angry_e);

            moodToRenderer(mood, 1, happy_renderer, sad_renderer, angry_renderer);
        })));
        auto& button_talk_ui = scene->addComponent<UIElement_C>(button_talk_e, UIElement_C(glm::vec2(810.0f, 940.0f), glm::vec2(200.0f, 75.0f)));
        button_talk_ui.canvas = canvas_e;

        Entity text_button_talk_e = scene->createEntity();
        auto& text_button_talk_transform = scene->addComponent<Transform_C>(text_button_talk_e, Transform_C(text_button_talk_e));
        auto& text_button_talk_renderer = scene->addComponent<MeshRenderer_C>(text_button_talk_e, MeshRenderer_C(std::make_shared<MaterialFont>(ShaderManager::get("font"), 20, std::vector<Asset>{14, 15, 18, 19})));
        auto mat_font_3 = std::dynamic_pointer_cast<MaterialFont>(text_button_talk_renderer.material);
        auto& text_button_talk_text = scene->addComponent<Text_C>(text_button_talk_e, Text_C(text_button_talk_e, mat_font_3->font));
        text_button_talk_text.text = "Talk";
        text_button_talk_text.text_size = 10;
        text_button_talk_text.color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        text_button_talk_text.alignment = TextAlign::CENTER;
        text_button_talk_text.v_alignment = VerticalAlign::CENTER;
        auto& text_button_talk_ui = scene->addComponent<UIElement_C>(text_button_talk_e, UIElement_C(glm::vec2(765.0f, 940.0f), glm::vec2(400.0f)));
        text_button_talk_ui.canvas = canvas_e;
        text_button_talk_ui.apply_scaling = false;
        text_button_talk_ui.anchor = glm::vec2(0.5f, 0.5f);


        Entity button_work_e = scene->createEntity();
        auto& button_work_transform = scene->addComponent<Transform_C>(button_work_e, Transform_C(button_work_e));
        auto& button_work_renderer = scene->addComponent<MeshRenderer_C>(button_work_e, MeshRenderer_C(std::make_shared<MaterialDefault>(ShaderManager::get("sprite"), 8)));
        auto& button_work_button = scene->addComponent<Button_C>(button_work_e, Button_C(([this, scene, happy_e, sad_e, angry_e, mood_e] () {
            auto* mood = &scene->getComponent<Mood_C>(mood_e);
            auto* happy_renderer = &scene->getComponent<MeshRenderer_C>(happy_e);
            auto* sad_renderer   = &scene->getComponent<MeshRenderer_C>(sad_e);
            auto* angry_renderer = &scene->getComponent<MeshRenderer_C>(angry_e);

            moodToRenderer(mood, 2, happy_renderer, sad_renderer, angry_renderer);
        })));
        auto& button_work_ui = scene->addComponent<UIElement_C>(button_work_e, UIElement_C(glm::vec2(510.0f, 940.0f), glm::vec2(200.0f, 75.0f)));
        button_work_ui.canvas = canvas_e;

        Entity text_button_work_e = scene->createEntity();
        auto& text_button_work_transform = scene->addComponent<Transform_C>(text_button_work_e, Transform_C(text_button_work_e));
        auto& text_button_work_renderer = scene->addComponent<MeshRenderer_C>(text_button_work_e, MeshRenderer_C(std::make_shared<MaterialFont>(ShaderManager::get("font"), 20, std::vector<Asset>{14, 15, 18, 19})));
        auto mat_font_4 = std::dynamic_pointer_cast<MaterialFont>(text_button_work_renderer.material);
        auto& text_button_work_text = scene->addComponent<Text_C>(text_button_work_e, Text_C(text_button_work_e, mat_font_4->font));
        text_button_work_text.text = "Work";
        text_button_work_text.text_size = 10;
        text_button_work_text.color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        text_button_work_text.alignment = TextAlign::CENTER;
        text_button_work_text.v_alignment = VerticalAlign::CENTER;
        auto& text_button_work_ui = scene->addComponent<UIElement_C>(text_button_work_e, UIElement_C(glm::vec2(465.0f, 940.0f), glm::vec2(400.0f)));
        text_button_work_ui.canvas = canvas_e;
        text_button_work_ui.apply_scaling = false;
        text_button_work_ui.anchor = glm::vec2(0.5f, 0.5f);
    }

    inline std::string getSceneName() const override {
        return "Game";
    }
};