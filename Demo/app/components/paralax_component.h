#pragma once
#include <glm/vec3.hpp>

class Paralax_C {
public:
    glm::vec3 intensity;
    float smoothing = 0.6f;
    bool is_enabled = true;

    glm::vec3 currentOffset{0.0f};

    Paralax_C() : intensity(0.05f) {}
    explicit Paralax_C(glm::vec3 _intensity) : intensity(_intensity) {}
    explicit Paralax_C(glm::vec3 _intensity, float _smoothing) : intensity(_intensity), smoothing(_smoothing) {}
};