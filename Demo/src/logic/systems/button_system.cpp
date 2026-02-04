#include "button_system.h"
#include "engine_variables.h"
#include "iostream"

struct MouseState
{
    double x;      // screen space pixels
    double y;
    bool leftDown;
};

MouseState GetMouseState()
{
    MouseState state{};
    glfwGetCursorPos(window, &state.x, &state.y);
    state.leftDown = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
    return state;
}

void Button_S::update()
{
    double mouseX, mouseY;
    MouseState mouse_state = GetMouseState();
    SystemManager::current_scene->forEach<UIElement_C, Button_C, MeshRenderer_C>(
    [this, &mouse_state](Entity e, UIElement_C& ui_element, Button_C& button, MeshRenderer_C& mesh_renderer) {
        bool isHovering = mouse_state.x >= ui_element.position.x - ui_element.size.x * 0.5f && mouse_state.x <= ui_element.position.x + ui_element.size.x * 0.5f &&
                          mouse_state.y >= ui_element.position.y - ui_element.size.y * 0.5f && mouse_state.y <= ui_element.position.y + ui_element.size.y * 0.5f;
        button.hovered = isHovering;

        if (isHovering) {
            button.hovered = true;
            if (mouse_state.leftDown) {
                if (!button.pressed && button.onClick) {
                    button.onClick();
                }
                button.pressed = true;
            }
            else {
                button.pressed = false;
            }
        }
        else {
            button.hovered = false;
            button.pressed = false;
        }

        if (auto mat = std::dynamic_pointer_cast<MaterialDefault>(mesh_renderer.material)) {
            if (button.hovered) {
                mat->color = button.hoverColor;
            } else {
                mat->color = button.normalColor;
            }
        }
    });
}