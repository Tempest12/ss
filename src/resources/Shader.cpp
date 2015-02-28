#include <iostream>
#include <string>
#include <vector>

#include <string.h>
//#include <GL/glew.h>
//#include <GL/glut.h>

#include "main/Main.hpp"
#include "resources/Shader.hpp"
#include "util/Log.hpp"
#include "util/Parsing.hpp"
#include "util/StringLib.hpp"

using namespace Resources;

Shader::Shader(char* fileName)
{
    this->name.assign(fileName);

    this->getTypeFromFileName();

    if(this->type == INVALID)
    {
        return;
    }

    //Create Shader and set the source.
    //this->id = glCreateShader(this->type);

    this->setSource();
    
    this->compile();
}

Shader::~Shader(void)
{
}

void Shader::compile(void)
{
    int errorCode = 0;

    //glCompileShader(this->id);
    
    //glGetShaderiv(this->id, GL_COMPILE_STATUS, &errorCode);
    
    if(errorCode == GL_FALSE)
    {
        //Compilation has failed.  We're going to quit but we want to see the error message.
        int logSize = 0;
        char* errorLog;    
        
        //glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &logSize);   
        errorLog = new char[logSize];
        //glGetShaderInfoLog(this->id, logSize, NULL, errorLog);
    
        Util::Log::writeFatal("Shader \"" + this->name + "\" Failed to compile.  Compilation error message \"" + errorLog + "\".");
        Main::die("Shader \"" + this->name + "\" Failed to compile.  Compilation error message \"" + errorLog + "\".");
    }
}

void Shader::getTypeFromFileName(void)
{
    std::string* pieces;
    std::string* temp;
    int count;
    
    pieces = Util::StringLib::split(&this->name, '.', &count);

    temp = &pieces[count - 1];
    
    if(Util::StringLib::equalsIgnoreCase(    temp,  VertexShaderExtension))
    {
        this->type = VERTEX;
    }
    else if(Util::StringLib::equalsIgnoreCase(temp, TessCtrlShaderExtension))
    {
        this->type = TESSCONTROL;
    }
    else if(Util::StringLib::equalsIgnoreCase(temp, TessEvalShaderExtension))
    {
        this->type = TESSEVAL;
    }
    else if(Util::StringLib::equalsIgnoreCase(temp, GeometryShaderExtension))
    {
        this->type = GEOMETRY;
    }
    else if(Util::StringLib::equalsIgnoreCase(temp, FragmentShaderExtension))
    {
        this->type = FRAGMENT;
    }
    else if(Util::StringLib::equalsIgnoreCase(temp, ComputeShaderExtension))
    {
        this->type = COMPUTE;
    }
    else
    {
        Util::Log::writeError("File: " + this->name + " isn't a shader file.");
        this->type = INVALID;
    }
    
    delete[] pieces;
}

void Shader::setSource(void)
{
    std::vector<std::string*>* strings = Util::Parsing::getStringArray(&this->name);
    unsigned int shaderLength = 0;
    unsigned int count = 0;
    char* shaderSource;
    
    for(unsigned int index = 0; index < strings->size(); index++)
    {
        shaderLength += (*strings)[index]->length();
    }
    
    
    if(shaderLength == 0)
    {
        Main::die("Shader file: " + this->name + " is empty");
    }
    else //Add space for a null terminator.
    {
        shaderLength++;
    }
    
    shaderSource = new char[shaderLength];
    shaderSource[shaderLength - 1] = '\0';
    
    
    for(unsigned int index = 0; index < strings->size(); index++)
    {
        memcpy(&shaderSource[count], (*strings)[index]->c_str(), (*strings)[index]->length());
        count += (*strings)[index]->length();
    }
    
    //Set the source:
    //glShaderSource(this->id, 1, (const char**)&shaderSource, (int*)&shaderLength);
    
    //Clean up:
    delete[] shaderSource;    
    delete strings;    
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Static Stuff:
///////////////////////////////////////////////////////////////////////////////////////////////////

std::string Shader::VertexShaderExtension   = "vert";
std::string Shader::TessCtrlShaderExtension = "tessCtrl";
std::string Shader::TessEvalShaderExtension = "tessEval";
std::string Shader::GeometryShaderExtension = "geom";
std::string Shader::FragmentShaderExtension = "frag";
std::string Shader::ComputeShaderExtension  = "comp";