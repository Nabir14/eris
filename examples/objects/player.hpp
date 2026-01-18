#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <game/game_object.hpp>
#include <core/renderer.hpp>

namespace Player {
    class Player : public GameObject::GameObject {
        public:
            Mesh::Mesh shape = Mesh::Mesh(Primitives::Triangle::vertices, Primitives::Triangle::indecies);
            Material::Material mat = Material::Material(Material::StandardMaterial::vertexShaderSource, Material::StandardMaterial::fragmentShaderSource);
        
        Player();
        void OnLoad() override;
        void OnUpdate() override;
        void OnDraw() override;
    };
}

#endif