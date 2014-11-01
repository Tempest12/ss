#ifndef _RESOURCES_SHADERPROGRAM_HPP
#define _RESOURCES_SHADERPROGRAM_HPP

#include <string>

namespace Resources
{
    //Forward Declarations:
    class Shader;


    class ShaderProgram
    {
    
    //Variables:
    public:
        
        int id;
        
        bool status;
        
        std::string name;
    
    protected:
    private:
    
        Shader* shaders[5];
        int     shaderCount;
    
    //Functions:
    public:
    
        ShaderProgram(char* fileName);
        ~ShaderProgram();
        
        void link(void);
    
    protected:
    private:
    };
}

#endif
