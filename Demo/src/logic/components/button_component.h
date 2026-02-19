#pragma once
#include <functional>
#include <glm/glm.hpp>

struct Button_C
{
    bool hovered = false;
    bool pressed = false;
    bool enabled = true;

    glm::vec4 normalColor = glm::vec4(1.0f);
    glm::vec4 hoverColor = glm::vec4(0.8f, 0.8f, 0.8f, 1.0f);

    std::function<void()> onClick;

    Button_C() = default;

    Button_C(std::function<void()> callback)
        : onClick(std::move(callback)) {}
};