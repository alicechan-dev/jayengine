#include "Camera.h"

Camera::Camera(glm::vec3 pos, size_t width, size_t height)
{
    this->width = width;
    this->height = height;

    this->Pos = pos;
}

// projection of view (perspective or orthographic)
glm::mat4 Camera::getProj()
{
    return this->projection;
}

glm::mat4 Camera::getView()
{
    return this->view;
}

void Camera::use()
{
    this->projection = glm::perspective(glm::radians(45.f), (float)this->width / (float)this->height, .1f, 100.f);
    this->view = glm::lookAt(this->Pos, this->Pos + this->Front, this->Up);
}

void Camera::ProcessInput(Camera_Movement direction, float deltatime)
{
    float velocity = this->movementSpeed * deltatime;

    if (direction == FORWARD)
    switch (direction)
    {
    case FORWARD:
        this->Pos += Front * velocity;
    case BACKWARD:
        this->Pos -= Front * velocity;
    case LEFT:
        this->Pos += Up * velocity;
    case RIGHT:
        this->Pos -= Up * velocity;
    }
}