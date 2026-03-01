#include <logic/system_manager.h>
#include <logic/scene_manager.h>
#include <config_system.h>
#include <logic/components/transform_component.h>
#include <logic/components/mesh_renderer_component.h>
#include <iostream>
#include <engine_variables.h>
#include <util/time.h>

std::vector<System*> SystemManager::systems = {
    new Time(),
    new Transform_S(),
    new Canvas_S(),
    new SpriteRenderer_S(),
    new Button_S(),
    new Parallax_S()
};

Scene* SystemManager::current_scene = nullptr;

void SystemManager::update()
{
    if (!systems.empty()) systems[0]->update();
    
    for (int i = 1; i < static_cast<int>(systems.size()); ++i) {
        systems[i]->update();
    }
}

void SystemManager::awake()
{
    for (System* sys : systems) {
        sys->awake();
    }
}

void SystemManager::start()
{
    for (System* sys : systems) {
        sys->start();
    }
}

