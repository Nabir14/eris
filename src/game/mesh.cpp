#include <glad/glad.h>
#include "mesh.hpp"
#include <cstdio>

namespace Mesh {
    const std::vector<float> Primitives::Triangle = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
        };
    
    Mesh::Mesh(const std::vector<float> vertices) {
        this->verticies = vertices;
        for (int i = 0; i < this->verticies.size(); i++) {
            printf("%f\n", this->verticies.at(i));
        }
        
        glGenVertexArrays(1, &this->VAO);
        glBindVertexArray(this->VAO);
        glGenBuffers(1, &this->VBO);
        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
        glBufferData(GL_ARRAY_BUFFER, this->verticies.size() * sizeof(float), this->verticies.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float),(void*)0);
        glEnableVertexAttribArray(0);
    }
}