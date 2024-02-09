#pragma once

#include <glad/glad.h>
#include <iostream>

// create texture

class Texture
{
public:
    Texture(const char* path, bool isSecondary = false);

    unsigned int ID;
    void use(GLenum textureUnit = GL_TEXTURE0);
};

// use texture
