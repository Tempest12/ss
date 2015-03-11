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
    
        ShaderProgram(std::string* fileName);
        ~ShaderProgram();
        
        void link(void);
    
    protected:
    private:

    //Static Variables:
    public:
        static std::string FileExtension;

    protected:
    private:

    //Static Functions:
    public:
    protected:
    private:
    };
}

#endif
