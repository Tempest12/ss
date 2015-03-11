#ifndef _RESOURCES_SHADERMANAGER_HPP
#define _RESOURCES_SHADERMANAGER_HPP

#include <string>
#include <vector>

namespace Resources
{
    //Forward delclarations:
    class Shader;
    class ShaderProgram;

    class ShaderManager
    {
    //Variables:
    public:
    protected:
    private:
        std::vector<Shader*>        shaders;
        std::vector<ShaderProgram*> programs;

    //Functions:
    public:
        
        Shader*        getShader(const std::string* name);
        ShaderProgram* getShaderProgram(const std::string* name);
            
    protected:
    private:

        void loadShaders(void);
        void loadPrograms(void);

        //Singleton:
        ShaderManager(void);
        ~ShaderManager(void);

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    // Static Stuff:
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    public:
    protected:
    private:
        static std::string    shaderDirectory;
        static ShaderManager* shaderManager;

    //Static Functions:
    public:

        static ShaderManager* getShaderManager(void);
        static void           init(void);
        static void           uninit(void);

    protected:
    private:
    };
}

#endif