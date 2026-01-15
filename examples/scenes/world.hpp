#ifndef WORLD_HPP
#define WORLD_HPP

#include "../../src/core/scene_manager.hpp"

namespace World {
    class World : public SceneManager::Scene {
        public:
            const char* text;
        World();
        void OnLoad() override;
        void OnUpdate() override;
        void OnDraw() override;
    };
}

#endif