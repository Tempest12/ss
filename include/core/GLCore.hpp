#ifndef _CORE_GLCORE_HPP
#define _CORE_GLCORE_HPP

#include <chrono>

//Forward declarations:
namespace Levels
{
    class Level;
}

namespace Core
{
    class GLCore
    {
    //Variables:
    public:
    protected:
    private:

    //Functions:
    public:
        static void init(int argc, char** argv);
        static void uninit(int returnCode);

        static void draw(void);
        static void functionKeys(int keyCode, int positionX, int positionY);

        static void glutWarning(const char* message, va_list ap);
        static void glutError  (const char* mesaage, va_list ap);

        static void keyboard(unsigned char keyCode, int positionX, int positionY);
        static void mouseClick(int buttonCode, int buttonState, int positionX, int positionY);
        static void mouseActiveMotion(int positionX, int positionY);
        static void mousePassiveMotion(int positionX, int positionY);

        static void runLoop(void);

        static void update(float time);

    protected:
    private:
    };
}
#endif
