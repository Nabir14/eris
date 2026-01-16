#ifndef MATERIAL_HPP
#define METARIAL_HPP

namespace Material {
    class StandardMaterial {
        public:
            const char* vertexShader = "#version 330 core"
                                        "layout (location = 0) in vec3 attributePosition"
                                        "void main() {"
                                        "   glPosition = vec4(attributePosition.x, attributePosition.y, attributePosition.z, 1.0);"
                                        "}";
            const char* fragmentShader = "";
    };
}

#endif