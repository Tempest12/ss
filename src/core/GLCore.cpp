#include <chrono>
#include <iostream>
#include <random>
#include <vector>


#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>


//#include "core/Camera.hpp"
#include "core/GLCore.hpp"
#include "math/Vector3f.hpp"
#include "resources/Texture.hpp"
#include "util/Config.hpp"
#include "util/Log.hpp"

//The namespace this code belongs to:
using namespace Core;

//static int windowID;

static std::chrono::high_resolution_clock::time_point lastClock;
static std::chrono::high_resolution_clock::time_point currentClock;

void GLCore::init(int argc, char** argv)
{
}

void GLCore::draw(void)
{
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
	update(std::chrono::duration_cast<std::chrono::duration<float>>(currentClock - lastClock).count());
	lastClock = currentClock;

	draw();

	//glutPostRedisplay(); Is this needed?
}

void GLCore::uninit(int returnCode)
{
	Util::Log::uninit();
	Util::Config::uninit();

	exit(returnCode);
}

void GLCore::update(float deltaTime)
{
}