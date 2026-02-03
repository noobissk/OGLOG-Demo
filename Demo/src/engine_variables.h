#pragma once
#include <config_render.h>
#include <string>
#include <shader.h>

static const glm::vec3 right   (1.0f, 0.0f, 0.0f);
static const glm::vec3 up      (0.0f, 1.0f, 0.0f);
static const glm::vec3 forward (0.0f, 0.0f, 1.0f);

static glm::ivec2 resolution (1920, 1080);

static glm::vec3 screen_color (0.0f, 0.0f, 0.0f);

extern GLFWwindow* window;