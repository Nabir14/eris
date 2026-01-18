#ifndef MATERIAL_HPP
#define MATERIAL_HPP

namespace Material {
    class Material {
        public:
            unsigned int shaderProgram;
            Material(const char* vertexShaderSource, const char* fragmentShaderSource);
    };

    class StandardMaterial {
        public:
            inline static const char* vertexShaderSource = "#version 330 core\n"
                                        "layout (location = 0) in vec3 attributePosition;"
                                        "void main() {\n"
                                        "   gl_Position = vec4(attributePosition.x, attributePosition.y, attributePosition.z, 1.0);\n"
                                        "}\0";
            inline static const char* fragmentShaderSource = "#version 330 core\n"
                                        "out vec4 FragColor;\n"
                                        "void main() {\n"
                                        "   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
                                        "}\0";
    };
}

#endif