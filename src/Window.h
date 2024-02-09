#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <functional>
#include "Camera.h"

class Window
{
public:
    Window(size_t width, size_t height);
    ~Window();

    void maintainWindow(std::function<void(void)> anonym_funcs);

    float getDeltaTime();

private:
    GLFWwindow* window;

    float deltaTime = .0f;
    float lastFrame = .0f;
};