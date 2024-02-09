#pragma once
// math stuff
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform
{
public:
    Transform(glm::vec3 position, glm::vec3 rotation);
    glm::vec3 getPosition();
    glm::vec3 getRotation();
    glm::mat4 getModel();

    void setPosition(glm::vec3 position);
    void setRotation(glm::vec3 rotation);

private:
    // the core of the transform
    glm::mat4 model;

    glm::vec3 position;
    glm::vec3 rotation;
};
