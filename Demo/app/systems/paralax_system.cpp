#include "paralax_system.h"
#include <engine_variables.h>
#include <glm/glm.hpp>
#include <util/time.h>

void Parallax_S::start() {

    SystemManager::current_scene->forEach<Transform_C, Paralax_C>(
    [this](Entity e, Transform_C& transform_c, Paralax_C& paralax_c) {
        double mouseX, mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);
    
        // Normalize mouse position to range [-1, 1]
        float normMouseX = -((static_cast<float>(mouseX) / static_cast<float>(resolution.x) + 1.0f) * 2.0f);
        float normMouseY = -((static_cast<float>(mouseY) / static_cast<float>(resolution.y) + 1.0f) * 2.0f);
    
        // Calculate parallax offset
        glm::vec3 targetOffset = glm::vec3(
             normMouseX * paralax_c.intensity.x,
            -normMouseY * paralax_c.intensity.y,
             0.0f
        );
        paralax_c.currentOffset = targetOffset;
    });
}

void Parallax_S::update() {
    SystemManager::current_scene->forEach<Transform_C, Paralax_C>(
    [this](Entity e, Transform_C& transform_c, Paralax_C& paralax_c) {

        if (!paralax_c.enabled) {
            return; // Skip if parallax is disabled
        }

        double mouseX, mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        // Normalize mouse position to range [-1, 1]
        float normMouseX = -((static_cast<float>(mouseX) / static_cast<float>(resolution.x) + 1.0f) * 2.0f);
        float normMouseY = -((static_cast<float>(mouseY) / static_cast<float>(resolution.y) + 1.0f) * 2.0f);

        // Calculate parallax offset
        glm::vec3 targetOffset = glm::vec3(
             normMouseX * paralax_c.intensity.x,
            -normMouseY * paralax_c.intensity.y,
             0.0f
        );

        paralax_c.currentOffset = glm::mix(paralax_c.currentOffset, targetOffset, paralax_c.smoothing * Time::delta);
        transform_c.position = transform_c.position + paralax_c.currentOffset;
    });
}