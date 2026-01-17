#include <glad/glad.h>
#include "renderer.hpp"

namespace Renderer {
    void Renderer::Clear(Color::RGBA clearColor) {
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::Render(Mesh::Mesh *mesh, Material::Material *material) {
        unsigned int VBO, VBO;
        glGenVertexArrays(1, &VBO);
        glBindVertexArray(VBO);
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, mesh->verticies.size(), &mesh->verticies, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float),(void*)0);
        glEnableVertexAttribArray(0);
        glUseProgram(material->shaderProgram);
        glBindVertexArray(VBO);
    }
}