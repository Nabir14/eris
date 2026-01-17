#include "mesh.hpp"

namespace Mesh {
    const float Primitives::Triangle[9] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
        };
    
    Mesh::Mesh(const float vertices[]) {
        for (int i = 0; i < sizeof(vertices)/sizeof(float); i++) {
            this->verticies.push_back(vertices[i]);
        }
    }
}