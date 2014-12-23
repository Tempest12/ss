#include <iostream>

#include <GL/freeglut.h>

#include "levels/Level.hpp"
#include "levels/DemoLevel.hpp"
#include "util/Config.hpp"

using namespace Levels;

DemoLevel::DemoLevel(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(0.0f);
}

DemoLevel::~DemoLevel(void)
{
}

void DemoLevel::mouseActiveMovement(int positionX, int positionY)
{
}

void DemoLevel::mousePassiveMovement(int positionX, int positionY)
{
}

void DemoLevel::mouseClick(int buttonCode, int buttonState, int positionX, int positionY)
{
}

void DemoLevel::keyInput(unsigned char keyCode, int modifierKeys)
{	
}

void DemoLevel::render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_POINTS);

	for(float x = -1.0; x <= 1.0; x+= 0.00125)
	{
		glVertex2f(x, x);
	}

	for(float x = -1.0; x <= 1.0; x+= 0.00125)
	{
		glVertex2f(x, -x);
	}

	glEnd();

	glutSwapBuffers();
}

bool DemoLevel::update(float time)
{
	return true;
}