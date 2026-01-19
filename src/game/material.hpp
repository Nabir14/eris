#ifndef MATERIAL_HPP
#define MATERIAL_HPP

namespace Material {
    class Material {
        public:
            unsigned int shaderProgram;
            Material(const char* vertexShaderSource, const char* fragmentShaderSource);
            
            void setUniformValue(const char* alias, float value);
            void setUniformValue(const char* alias, int value);
            void setUniformValue(const char* alias, bool value);
            void setUnfiromValue(const char* alias, unsigned int value);
            void setUniformValue(const char* alias, int x, int y);
            void setUniformValue(const char* alias, int x, int y, int z);
            void setUniformValue(const char* alias, int x, int y, int z, int w);
            void setUniformValue(const char* alias, float x, float y);
            void setUniformValue(const char* alias, float x, float y, float z);
            void setUniformValue(const char* alias, float x, float y, float z, float w);
            
            void getUniformValue(const char* alias, float value);
            void getUniformValue(const char* alias, int value);
            void getUniformValue(const char* alias, bool value);
            void getUnfiromValue(const char* alias, unsigned int value);
            void getUniformValue(const char* alias, int x, int y);
            void getUniformValue(const char* alias, int x, int y, int z);
            void getUniformValue(const char* alias, int x, int y, int z, int w);
            void getUniformValue(const char* alias, float x, float y);
            void getUniformValue(const char* alias, float x, float y, float z);
            void getUniformValue(const char* alias, float x, float y, float z, float w);
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
                                        "uniform vec3 baseColor;"
                                        "uniform float alpha;"
                                        "void main() {\n"
                                        "   FragColor = vec4(baseColor, alpha);\n"
                                        "}\0";
    };
}

#endif