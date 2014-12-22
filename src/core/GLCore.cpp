#include <chrono>
#include <iostream>
#include <random>
#include <vector>


#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>


#include "core/GLCore.hpp"
#include "levels/LevelList.hpp"
#include "math/Vector3f.hpp"
#include "resources/Texture.hpp"
#include "util/Config.hpp"
#include "util/Log.hpp"

//The namespace this code belongs to:
using namespace Core;

//static int windowID;

static std::chrono::high_resolution_clock::time_point lastClock;
static std::chrono::high_resolution_clock::time_point currentClock;
static Levels::Level* currentLevel;

void GLCore::init(int argc, char** argv)
{
	//Context init:
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitContextVersion(3, 0);
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);

	//Window init:
	glutInitWindowSize(Util::Config::convertSettingToInt("window", "width" ),
					   Util::Config::convertSettingToInt("window", "height"));
	glutCreateWindow("Solar Shard");

	//Register Callbacks:
	glutDisplayFunc      (GLCore::draw);
	glutIdleFunc         (GLCore::runLoop);
	glutKeyboardFunc     (GLCore::keyboard);
	glutMouseFunc        (GLCore::mouseClick);
	glutMotionFunc       (GLCore::mouseActiveMotion);
	glutPassiveMotionFunc(GLCore::mousePassiveMotion);
	glutSpecialFunc      (GLCore::functionKeys);

	//glutPostRedisplay();
	currentLevel = new Levels::DemoLevel();
}

void GLCore::draw(void)
{
	currentLevel->render();

	glutPostRedisplay();
}

void GLCore::functionKeys(int keyCode, int positionX, int positionY)
{
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