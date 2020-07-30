#ifndef __SHADER_PROGRAM__
#define __SHADER_PROGRAM__

#include <stdio.h>

#include "window.h"
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "errors.h"
#include "types.h"

class ShaderProgram {
public:
    void Init(const std::map<GLenum, std::string>& );
    void Load();
    void Compile();
    void Link();
    void Run();
    void DeleteShaders();
    void Delete();
    //~ShaderProgram();

    void SetShaderParameters(uint32_t c) { shader_parameters = c; }
    void SetFractalType(FractalType c) { currentFractalType = c; }
    void SetBackgroundType(BackgroundType c) { currentBackgroundType = c; }

    void SetUniform(const char* name, const glm::vec2&);
    void SetUniform(const char* name, const glm::vec3&);
    void SetUniform(const char* name, const glm::mat4&);
    void SetUniform(const char* name, float value);
    void SetUniform(const char* name, int value);


    FractalType GetFractalType() { return currentFractalType; }

private:
    std::string version = "#version 330 core\n";
    std::string defines = "";
    std::map<GLenum, std::string> mapSources;
    std::map<GLenum, GLuint> mapShaders;
    GLuint descriptor;

    enum ShaderParametersType {
        HardShadows = 1 << 1,
        SoftShadows = 1 << 2,
        AO = 1 << 3,
    };

    uint32_t shader_parameters = 0;
    FractalType currentFractalType = FractalType::Test;
    BackgroundType currentBackgroundType = BackgroundType::Skybox;
};

#endif /* End of __SHADERPROGRAM__ */