#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "levels/Level.hpp"
#include "levels/DemoLevel.hpp"
#include "resources/Shader.hpp"
#include "resources/ShaderManager.hpp"
#include "resources/ShaderProgram.hpp"
#include "util/Config.hpp"

using namespace Levels;

DemoLevel::DemoLevel(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(0.0f);

    Resources::ShaderManager* shaderManager = Resources::ShaderManager::getShaderManager();

    std::string temp = "standardColor.pgm";

    this->shaderProgram = shaderManager->getShaderProgram(&temp);
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

    glUseProgram(this->shaderProgram->id);

    glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);

        glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f( 0.0f,  0.5f, 0.0f);

        glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
        glVertex3f( 0.5f, -0.5f, 0.0f);
    glEnd();
}

bool DemoLevel::update(float time)
{
    return true;
}