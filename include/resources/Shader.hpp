#ifndef _RESOURCES_SHADER_HPP
#define _RESOURCES_SHADER_HPP

#include <string>

#include <GL/glew.h>
#include <GL/freeglut.h>

namespace Resources
{
    enum ShaderType
    {
        //Supported:
        INVALID     = 0,
        VERTEX      = GL_VERTEX_SHADER,
        //TESSCONTROL = GL_TESS_CONTROL_SHADER,
        //TESSEVAL    = GL_TESS_EVALUATION_SHADER,
        GEOMETRY    = GL_GEOMETRY_SHADER,
        FRAGMENT    = GL_FRAGMENT_SHADER,
        //COMPUTE     = GL_COMPUTE_SHADER,

        //Unsupported:
        TESSCONTROL = -1,
        TESSEVAL    = -2,
        COMPUTE     = -3,
    };

    class Shader
    {

    //Variables:
    public:
        std::string  name;
        ShaderType   type;
        unsigned int id;

    protected:
    private:

    //Functions:
    public:

        Shader(std::string* fileName);
        ~Shader();

        void compile(void);
        void getTypeFromFileName(void);
        void setSource(void);
    
    protected:
    private:

    //Static Varaibles:
    public:
        static std::string VertexShaderExtension  ;
        static std::string TessCtrlShaderExtension; 
        static std::string TessEvalShaderExtension;
        static std::string GeometryShaderExtension;
        static std::string FragmentShaderExtension;
        static std::string ComputeShaderExtension ;
    };
}

#endif