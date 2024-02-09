#pragma once
#include <vector>
#include <list>

class Object
{
public:
    // container stuff
    // ability to care components such as transform
};

class Scene
{
public:
    Scene();
private:
    std::list<Object> objectList;
};