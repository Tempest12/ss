#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>


#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SDL2/SDL.h>


#include "core/GLCore.hpp"
#include "levels/LevelList.hpp"
#include "main/Main.hpp"
#include "math/Vector3f.hpp"
#include "resources/Texture.hpp"
#include "resources/ShaderManager.hpp"
#include "util/Config.hpp"
#include "util/Log.hpp"

//The namespace this code belongs to:
using namespace Core;

//static int windowID;

static std::stringstream* stringStream;

static char* glutErrorMessageBuffer;
static char* glutWarningMessageBuffer;

static std::chrono::high_resolution_clock::time_point lastClock;
static std::chrono::high_resolution_clock::time_point currentClock;
static Levels::Level* currentLevel;

void GLCore::init(int argc, char** argv)
{
    //Static varaibles:
    stringStream = new std::stringstream(std::ios_base::ate);

    glutErrorMessageBuffer   = new char[Util::Config::convertSettingToInt("glut", "errorMessageBufferSize")];
    glutWarningMessageBuffer = new char[Util::Config::convertSettingToInt("glut", "warningMessageBufferSize")];

    //Context init:
    glutInitErrorFunc(  GLCore::glutError);
    glutInitWarningFunc(GLCore::glutWarning);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInit(&argc, argv);
    //glutInitContextVersion(3, 0);
    //glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);

    //Window init:
    glutInitWindowSize(Util::Config::convertSettingToInt("window", "width" ),
                       Util::Config::convertSettingToInt("window", "height"));
    glutCreateWindow("Solar Shard");

    //Glew Init:
    GLenum errorCode = glewInit();

    if(errorCode != GLEW_OK)
    {
        Main::die("Unable to initialize glew.");
    }

    //Register Callbacks:
    /*glutDisplayFunc      (GLCore::draw);
    glutIdleFunc         (GLCore::runLoop);
    glutKeyboardFunc     (GLCore::keyboard);
    glutMouseFunc        (GLCore::mouseClick);
    glutMotionFunc       (GLCore::mouseActiveMotion);
    glutPassiveMotionFunc(GLCore::mousePassiveMotion);
    glutSpecialFunc      (GLCore::functionKeys);*/

    //Load resources:
    Resources::ShaderManager::init();

    //glutPostRedisplay();
    currentLevel = new Levels::DemoLevel();
}

void GLCore::draw(void)
{
    currentLevel->render();

    //glutPostRedisplay();
}

void GLCore::functionKeys(int keyCode, int positionX, int positionY)
{
}

void GLCore::glutWarning(const char* message, va_list parameters)
{
    memset(glutWarningMessageBuffer, 0, Util::Config::convertSettingToInt("glut", "warningMessageBufferSize"));

    vsnprintf(glutWarningMessageBuffer, 
             Util::Config::convertSettingToInt("glut", "warningMessageBufferSize"),
             message,
             parameters);

    *stringStream << "Warning from glut: ";
    *stringStream << glutWarningMessageBuffer;

    Util::Log::writeError(stringStream->str());
}

void GLCore::glutError(const char* message, va_list parameters)
{
    memset(glutErrorMessageBuffer, 0, Util::Config::convertSettingToInt("glut", "errorMessageBufferSize"));

    vsnprintf(glutErrorMessageBuffer, 
             Util::Config::convertSettingToInt("glut", "errorMessageBufferSize"),
             message,
             parameters);

    *stringStream << "Error from glut: ";
    *stringStream << glutErrorMessageBuffer;

    Util::Log::writeFatal(stringStream->str());
}

void GLCore::keyboard(unsigned char keyCode, int positionX, int positionY)
{
    keyCode = tolower(keyCode);

    if(keyCode == 27)//KeyCode for escape.
    {
        uninit(0);
    }
}

void GLCore::mouseClick(int buttonCode, int buttonState, int positionX, int positionY)
{
}

void GLCore::mouseActiveMotion(int positionX, int positionY)
{
}

void GLCore::mousePassiveMotion(int positionX, int positionY)
{
}

void GLCore::runLoop(void)
{
    currentClock = std::chrono::high_resolution_clock::now();
    float temp = std::chrono::duration_cast<std::chrono::duration<float>>(currentClock - lastClock).count();
    lastClock = currentClock;

    currentLevel->update(temp);
}

void GLCore::uninit(int returnCode)
{
    Util::Log::uninit();
    Util::Config::uninit();

    exit(returnCode);
}