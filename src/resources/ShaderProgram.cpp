#include <iostream>
#include <string>
#include <vector>

#include <string.h>
#include <GL/glew.h>
#include <GL/glut.h>

#include "main/Main.hpp"
#include "resources/Shader.hpp"
#include "resources/ShaderManager.hpp"
#include "resources/ShaderProgram.hpp"
#include "util/Log.hpp"
#include "util/Parsing.hpp"
#include "util/StringLib.hpp"

using namespace Resources;

//Local debug status for this code:
static LogLevel localDebugLevel = INFO;

ShaderProgram::ShaderProgram(std::string* fileName)
{
    this->name.assign(*fileName);
    this->status = true;

    this->id          = glCreateProgram();
    this->shaderCount = 0;

    ShaderManager*             shaderManager = ShaderManager::getShaderManager();
    std::vector<std::string*>* strings       = Util::Parsing::getStringArray(&this->name);
    int                        linkStatus    = 0;


    for(unsigned int index = 0; index < strings->size(); index++)
    {
        //Ignore blank and comment lines.
        if(Util::StringLib::isWhiteSpace((*strings)[index])       ||
           Util::StringLib::startsWith((*strings)[index], "\\\\") ||
           Util::StringLib::startsWith((*strings)[index], "#"))    
        {
            continue;
        }

        this->shaders[this->shaderCount] = shaderManager->getShader((*strings)[index]);
        glAttachShader(this->id, this->shaders[shaderCount]->id);
        this->shaderCount++;
    }

    glLinkProgram( this->id); 
    glGetProgramiv(this->id, GL_LINK_STATUS, &linkStatus);

    if(linkStatus == 0) //GL_FALSE
    {
        char* errorLogBuffer = NULL;
        int   errorLength    = 0;

        glGetProgramiv(this->id, GL_INFO_LOG_LENGTH, &errorLength);
        errorLogBuffer = new char[errorLength];
        memset(errorLogBuffer, 0, errorLength);
        glGetProgramInfoLog(this->id, errorLength, NULL, errorLogBuffer);

        Main::die(errorLogBuffer);
    }

    delete strings;
}

ShaderProgram::~ShaderProgram()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Static Stuff:
///////////////////////////////////////////////////////////////////////////////////////////////////
std::string ShaderProgram::FileExtension = "pgm";