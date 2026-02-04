
#pragma once
#include <string>
#include <service/asset_manager.h>
#include <util/texture.h>
#include <engine_variables.h>
#include "material.h"

using Asset = uint16_t;

class MaterialDefault : public Material{
public:
    Texture texture;
    glm::vec4 color = glm::vec4(1.0f);

    MaterialDefault(Shader* _shader, Asset texture_asset);
    MaterialDefault(Shader* _shader, Texture _texture);
    // void applyTexture(int texture);
    void use() override;
    ~MaterialDefault();
};