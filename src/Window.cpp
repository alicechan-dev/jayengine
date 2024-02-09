#include <iostream>
#include "Window.h"

void processInput(GLFWwindow *window, Window windowClass, Camera camera)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessInput(Camera::FORWARD, windowClass.getDeltaTime());
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessInput(Camera::BACKWARD, windowClass.getDeltaTime());
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessInput(Camera::LEFT, windowClass.getDeltaTime());
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessInput(Camera::RIGHT, windowClass.getDeltaTime());
}

Window::Window(size_t width, size_t height)
{
    // GLFW context version definition
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    // Definition of OpenGL profile Core/Compability
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // init GLFW stuff
    if(!glfwInit())
        //return -1;
        throw std::runtime_error("Failed GLFW init");
    
    window = glfwCreateWindow(width, height, "Hello World", nullptr, nullptr);
    if(!window)
    {
        glfwTerminate();
        //return -1;
        throw std::runtime_error("Failed to create a window");
    }
    // after creating make the context
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

float Window::getDeltaTime()
{
    return this->deltaTime;
}

void Window::maintainWindow(std::function<void(void)> anonym_funcs)
{
    while (!glfwWindowShouldClose(this->window))
    {
        // frame processing event
        float currentTime = static_cast<float>(glfwGetTime());
        this->deltaTime = this->lastFrame - currentTime;
        this->lastFrame = currentTime;

        // the size of the window which could be changed just in time
        int width, height;
        
        // we need to mund that's the starting point of certain view's rendering
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        
        // we need to eenable the depth of view for correct rendering
        glEnable(GL_DEPTH_TEST);

        // arrange the clear color to clear the rendering section
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     

        processInput(this->window, window, )   

        // Do any unrelated with window functions
        anonym_funcs();

        // swap buffers and process any past events 
        glfwSwapBuffers(window);
        glfwPollEvents();

        std::cout << this->deltaTime << std::endl;
    }
}
