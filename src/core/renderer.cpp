#include <glad/glad.h>
#include "renderer.hpp"

namespace Renderer {
    void Renderer::Clear(Color::RGBA clearColor) {
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::Render(Mesh::Mesh *mesh, Material::Material *material) {
        glUseProgram(material->shaderProgram);
        glBindVertexArray(mesh->VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}