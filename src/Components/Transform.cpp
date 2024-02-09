#include "Transform.h"

Transform::Transform(glm::vec3 position, glm::vec3 rotation)
{
    model = glm::mat4(1.0f);
    
    setPosition(position);
    setRotation(rotation);
}

glm::vec3 Transform::getPosition()
{
    return this->position;
}

void Transform::setPosition(glm::vec3 position)
{
    model = glm::translate(model, position);
}

void Transform::setRotation(glm::vec3 rotation)
{
    float angleX = rotation.x;
    model = glm::rotate(model, glm::radians(angleX), glm::vec3(1.0f, 0.0f, 0.0f));
    
    float angleY = rotation.y;
    model = glm::rotate(model, glm::radians(angleY), glm::vec3(0.0f, 1.0f, 0.0f));

    float angleZ = rotation.z;
    model = glm::rotate(model, glm::radians(angleZ), glm::vec3(0.0f, 0.0f, 1.0f));
}

glm::mat4 Transform::getModel()
{
    return this->model;
}