#include <engine.h>
#include <config_system.h>
#include <logic/system_manager.h>
#include <logic/scene_manager.h>
#include <misc/colors.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <service/asset_manager.h>
#include <scene_init.h>



GLFWwindow* window = nullptr;
ShaderManager shader_manager();
SceneController_S scene_controller();

void Engine::frameBufferSizeCallback(int width, int height)
{
    resolution = glm::ivec2(width, height);
    glViewport(0, 0, width, height);
}


int Engine::startUp()
{
    std::cout << "[LOG] (Egnine) startup!" << std::endl;
    AssetManager::start();


    try {
        ShaderManager::load("sprite", 11, 7);
        ShaderManager::load("font", 10, 4);

        SceneController_S::initialize();

        std::cout << "[LOG] Awakening systems..." << std::endl;
        SystemManager::awake();
        
        screen_color = Colors::program_default;
        glClearColor(screen_color.r, screen_color.g, screen_color.b, 1.0f);
        
        std::cout << "[LOG] Starting main loop..." << std::endl;
        SystemManager::start();

        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();

            glClear(GL_COLOR_BUFFER_BIT);

            SystemManager::update();

            glfwSwapBuffers(window);
        }

        glfwTerminate();

        Engine::quit();

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "[FATAL] Exception caught in main loop: " << e.what() << std::endl;
        glfwTerminate();
        return -1;
    }
    catch (...) {
        std::cerr << "[FATAL] Unknown exception caught in main loop" << std::endl;
        glfwTerminate();
        return -1;
    }
}

void Engine::quit() { }