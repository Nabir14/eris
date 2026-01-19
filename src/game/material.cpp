#include <stdio.h>
#include <glad/glad.h>
#include "material.hpp"

namespace Material {
    Material::Material(const char* vertexShaderSource, const char* fragmentShaderSource) {
        int success;
        char log[512];
        
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);

        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, nullptr, log);
            printf("(Eris::Material) Shader Compilation Failed: %s.\n");
        }
        
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);

       glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, nullptr, log);
            printf("(Eris::Material) Shader Compilation Failed: %s.\n");
        }

        this->shaderProgram = glCreateProgram();
        glAttachShader(this->shaderProgram, vertexShader);
        glAttachShader(this->shaderProgram, fragmentShader);
        glLinkProgram(this->shaderProgram);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void Material::setUniformValue(const char* alias, float value) {
        int loc = glGetUniformLocation(this->shaderProgram, alias);
        glUniform1f(loc, value);
    }

    void Material::setUniformValue(const char* alias, float x, float y, float z) {
        int loc = glGetUniformLocation(this->shaderProgram, alias);
        glUniform3f(loc, x, y, z);
    }
}