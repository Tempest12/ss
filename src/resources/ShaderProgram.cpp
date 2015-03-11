#include <string>
#include <vector>

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
    //this->id = glCreateProgram();

    ShaderManager* shaderManager = ShaderManager::getShaderManager();
    std::vector<std::string*>* strings = Util::Parsing::getStringArray(&this->name);

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
        //glAttachShader(this->id, this->shaders[shaderCount]->id);
        this->shaderCount++;
    }

    //glLinkProgram(this->id);
}

ShaderProgram::~ShaderProgram()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Static Stuff:
///////////////////////////////////////////////////////////////////////////////////////////////////

std::string ShaderProgram::FileExtension = "pgm";