#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

namespace Mesh {
    class Mesh {
        public:
            unsigned int VBO, VAO, EBO;
            std::vector<float> verticies;
            std::vector<unsigned int> indecies;
        Mesh(const std::vector<float> vertices, const std::vector<unsigned int> indecies);
    };
}

namespace Primitives {
    class Triangle {
        public:
        static const std::vector<float> vertices;
        static const std::vector<unsigned int> indecies;
    };

    class Rect {
        public:
        static const std::vector<float> vertices;
        static const std::vector<unsigned int> indecies;
    };
}

#endif