#ifndef _LEVELS_DEMOLEVEL_HPP
#define _LEVELS_DEMOLEVEL_HPP

#include "Level.hpp"

namespace Resources
{
    class Shader;
    class ShaderManager;
    class ShaderProgram;
}

namespace Levels
{
    class DemoLevel: public Level
    {

    //Variables:
    public:
        Resources::ShaderProgram* shaderProgram;

    protected:
    private:

    //Functions:
    public:

        DemoLevel(void);
        ~DemoLevel(void);

        void mouseActiveMovement(int positionX, int positionY);
        void mousePassiveMovement(int positionX, int positionY);
        void mouseClick(int buttonCode, int buttonState, int positionX, int positionY);
        void keyInput(unsigned char keyCode, int modifierKeys);
        void render(void);
        bool update(float time);
        
    protected:
    private:

    };
}

#endif