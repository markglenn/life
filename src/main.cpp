#include <iostream>
#include "glm/vec3.hpp"

int main()
{
    glm::vec3 example = glm::vec3(0.0f, 1.0f, 2.0f);
    std::cout << "Hello World: " << example.y << std::endl;
    return 0;
}
