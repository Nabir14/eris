#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

namespace GameObject {
    class GameObject {
        public:
        virtual void OnLoad() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnDraw() = 0;
        virtual ~GameObject();
    };
}

#endif