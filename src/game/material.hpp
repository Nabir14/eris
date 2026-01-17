#ifndef MATERIAL_HPP
#define METARIAL_HPP

namespace Material {
    class Material {
        public:
            unsigned int shaderProgram;
            Material(const char* vertexShaderSource, const char* fragmentShaderSource);
    };

    class StandardMaterial {
        public:
            const char* vertexShaderSource = "#version 330 core\n"
                                        "layout (location = 0) in vec3 attributePosition\n"
                                        "void main() {\n"
                                        "   glPosition = vec4(attributePosition.x, attributePosition.y, attributePosition.z, 1.0);\n"
                                        "}\0";
            const char* fragmentShaderSource = "#version 330 core\n"
                                        "out vec4 FragColor;\n"
                                        "void main() {\n"
                                        "   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f );\n"
                                        "}\0";
    };
}

#endif