#ifndef _LEVELS_LEVEL_HPP
#define _LEVELS_LEVEL_HPP

#include <string>

namespace Levels
{
    class Level
    {

    //Variables:
    public:

        std::string name;

    protected:
    private:

    //Functions:
    public:

        virtual void mouseActiveMovement(int positionX, int positionY) = 0;
        virtual void mousePassiveMovement(int positionX, int positionY) = 0;
        virtual void mouseClick(int buttonCode, int buttonState, int positionX, int positionY) = 0;
        virtual void keyInput(unsigned char keyCode, int modifierKeys) = 0;
        virtual void render(void) = 0;
        virtual bool update(float timeStep) = 0;

    protected:
    private:

    };
}

#endif