#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

namespace Mesh {
    class Mesh {
        public:
            unsigned int VBO, VAO;
            std::vector<float> verticies;
        Mesh(const std::vector<float> vertices);
    };
    class Primitives {
        public:
        static const std::vector<float> Triangle;
    };
}

#endif