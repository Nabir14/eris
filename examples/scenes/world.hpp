#ifndef WORLD_HPP
#define WORLD_HPP

#include <core/scene_manager.hpp>
#include "../objects/player.hpp"

namespace World {
    class World : public SceneManager::Scene {
        public:
            const char* text;
            Player::Player player;
            //Player::Player player2;
        World();
        void OnLoad() override;
        void OnUpdate() override;
        void OnRender() override;
    };
}

#endif