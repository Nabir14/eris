#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "../utils/color.hpp"
#include "../game/material.hpp"
#include "../game/mesh.hpp"

namespace Renderer {
    class Renderer {
        public:
        static void Clear(Color::RGBA clearColor);
        static void Render(Mesh::Mesh *mesh, Material::Material *material);
    };
}

#endif