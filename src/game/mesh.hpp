#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

namespace Mesh {
    class Mesh {
        public:
            std::vector<const float> verticies;
        Mesh(const float vertices[]);
    };
    class Primitives {
        static const float Triangle[9];
    };
}

#endif