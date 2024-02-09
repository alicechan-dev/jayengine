// we need to create a camera
// also each of cameras needs to do the all of render work itself
#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
    enum Camera_Movement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

    Camera(glm::vec3 pos, size_t width, size_t height);
    void use();
    void ProcessInput(Camera_Movement direction, float deltatime);

    glm::mat4 getProj();
    glm::mat4 getView();
    
private:
    glm::vec3 Pos     = glm::vec3(.0f, .0f, 3.f);
    glm::vec3 Front   = glm::vec3(.0f, .0f, -1.f);
    glm::vec3 Up      = glm::vec3(.0f, 1.f, .0f);

    // are being used and able to get exported
    glm::mat4 projection;
    glm::mat4 view;

    size_t width;
    size_t height;

    float movementSpeed = .5f;
};