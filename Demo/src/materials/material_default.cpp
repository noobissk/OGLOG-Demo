#include "material_default.h"
#include <config_render.h>
#include <iostream>


MaterialDefault::MaterialDefault(Shader* _shader, Asset texture_asset) : Material(_shader), texture(AssetManager::assetToPath(texture_asset)), color(1.0f) { texture.uploadIfNeeded(4); }
MaterialDefault::MaterialDefault(Shader* _shader, Texture _texture) : Material(_shader), texture(std::move(_texture)), color(1.0f) { texture.uploadIfNeeded(4); }

void MaterialDefault::use() {
    glUseProgram(shader->gl_id);
    int loc = glGetUniformLocation(shader->gl_id, "ourTexture");
    if (loc != -1) {
        glUniform1i(loc, 0);
    }
    else return;

    texture.uploadIfNeeded(STBI_rgb_alpha);

    shader->setVec4("color", color);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture.gpu_texture);
}

MaterialDefault::~MaterialDefault() = default;