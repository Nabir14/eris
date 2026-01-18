#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

namespace Mesh {
    class Mesh {
        public:
            unsigned int VBO, VAO, EBO;
            std::vector<float> verticies;
            std::vector<float> indecies;
        Mesh(const std::vector<float> vertices, const std::vector<float> indecies);
    };
}

namespace Primitives {
    class Triangle {
        public:
        static const std::vector<float> vertices;
        static const std::vector<float> indecies;
    };

    class Rect {
        public:
        static const std::vector<float> vertices;
        static const std::vector<float> indecies;
    };
}

#endif