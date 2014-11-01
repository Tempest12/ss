#ifndef _RESOURCES_SHADER_HPP
#define _RESOURCES_SHADER_HPP

#include <string>

#include <GL/glew.h>
#include <GL/glut.h>


namespace Resources
{
    enum ShaderType
    {
        INVALID     = 0,
        VERTEX      = GL_VERTEX_SHADER,
        TESSCONTROL = GL_TESS_CONTROL_SHADER,
        TESSEVAL    = GL_TESS_EVALUATION_SHADER,
        GEOMETRY    = GL_GEOMETRY_SHADER,
        FRAGMENT    = GL_FRAGMENT_SHADER,
        //COMPUTE     = GL_COMPUTE_SHADER,
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
        
        Shader(char* fileName);
        ~Shader();
        
        void compile(void);
        void getTypeFromFileName(void);
        void setSource(void);
    
    protected:
    private:
    };
}

#endif
