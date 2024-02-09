#pragma once
#include <glad/glad.h>
#include <vector>

// math stuff
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// shader
#include "RenderComponents/Shader.h"

// transform
#include "Components/Transform.h"

class Geometry
{
public:
    Geometry(std::vector<float> vertices);
    ~Geometry();
    void use(Shader shader, glm::mat4 view, glm::mat4 proj, Transform transform);
private:
    // Array geometry buffer
    unsigned int VAO;

    // Other geometry buffer
    unsigned int VBO;

    // Indices geometry buffer
    unsigned int EBO;

    //unsigned int transformLoc;

    //float vertices*;
    //unsigned int indices[6];

    //void *vertData;
    //void *elemData;
};