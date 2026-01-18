#include <glad/glad.h>
#include "mesh.hpp"
#include <cstdio>

namespace Primitives {
    const std::vector<float> Triangle::vertices = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };

    const std::vector<float> Triangle::indecies = {};

    const std::vector<float> Rect::vertices = {
            -0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f,
            0.5f, 0.5f, 0.0f
    };

    const std::vector<float> Rect::indecies = {
        0, 1, 2,
        2, 3, 1
    };
}

namespace Mesh {    
    Mesh::Mesh(const std::vector<float> vertices, const std::vector<float> indecies) {
        this->verticies = vertices;
        this->indecies = indecies;
        for (int i = 0; i < this->verticies.size(); i++) {
            printf("%f\n", this->verticies.at(i));
        }
        
        glGenVertexArrays(1, &this->VAO);
        glBindVertexArray(this->VAO);
        
        glGenBuffers(1, &this->VBO);
        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
        glBufferData(GL_ARRAY_BUFFER, this->verticies.size() * sizeof(float), this->verticies.data(), GL_STATIC_DRAW);
        
        glGenBuffers(1, &this->EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indecies.size() * sizeof(float), this->indecies.data(), GL_STATIC_DRAW);
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float),(void*)0);
        glEnableVertexAttribArray(0);
    }
}