#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "../utils/color.hpp"

namespace Renderer {
    class Renderer {
        public:
        static void Clear(Color::RGBA clearColor);
    };

    class Mesh {
        static void Render(float verticies[]);
    };
}

#endif