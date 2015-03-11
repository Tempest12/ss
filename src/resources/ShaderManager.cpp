#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <dirent.h>

#include "main/Main.hpp"
#include "resources/Shader.hpp"
#include "resources/ShaderProgram.hpp"
#include "resources/ShaderManager.hpp"
#include "util/Config.hpp"
#include "util/Log.hpp"
#include "util/StringLib.hpp"

using namespace Resources;

//Debug status for this code:
static LogLevel localDebugLevel = SPECIAL;

ShaderManager::ShaderManager(void)
{
    this->shaders  = std::vector<Shader*>();
    this->programs = std::vector<ShaderProgram*>(); 

    this->loadShaders();
    Util::Log::writeAt(localDebugLevel, "Found and loaded " + std::to_string(this->shaders.size()) + " shaders.");

    this->loadPrograms();
    Util::Log::writeAt(localDebugLevel, "Found and loaded " + std::to_string(this->programs.size()) + " programs");
}

ShaderManager::~ShaderManager(void)
{
    for(unsigned int index = 0; index < this->shaders.size(); index++)
    {
        delete this->shaders[index];
    }
}

Shader* ShaderManager::getShader(const std::string* name)
{
    for(unsigned int index = 0; index < this->shaders.size(); index++)
    {
        if(name->compare(this->shaders[index]->name) == 0)
        {
            return this->shaders[index];
        }
    }
    
    Main::die("Shader Manager: Shader requested but, not found: " + *name);
    
    return NULL;
}

ShaderProgram* ShaderManager::getShaderProgram(const std::string* name)
{
    for(unsigned int index = 0; index < this->programs.size(); index++)
    {
        if(name->compare(this->programs[index]->name) == 0)
        {
            return this->programs[index];
        }
    }
    
    Main::die("Shader Manager:  Program requested but, not found: " + *name);
    
    return NULL;
}

void ShaderManager::loadShaders(void)
{
    DIR*           directory = opendir(shaderDirectory.c_str());
    struct dirent* fileName;
    Shader*        newShader;
    std::string    tempString;

    if(directory == NULL)
    {
        Main::die("Unable to open shader directory .");
    }

    fileName = readdir(directory);
    
    while(fileName != NULL)
    {
        tempString.assign(shaderDirectory);
        tempString.append(fileName->d_name);

        if(!Util::StringLib::endsWith(tempString, ShaderProgram::FileExtension))
        {
            newShader = new Shader(&tempString);

            std::cout << tempString << std::endl;

            if(newShader->type != INVALID)
            {
                this->shaders.push_back(newShader);
            }
            else
            {
                delete newShader;
            }
        }

        fileName = readdir(directory);
    }
}

void ShaderManager::loadPrograms(void)
{
    DIR*           directory = opendir(shaderDirectory.c_str());
    struct dirent* fileName;
    ShaderProgram* newProgram;
    std::string    tempString;

    if(directory == NULL)
    {
        Main::die("Unable to open shader directory .");
    }
    
    fileName = readdir(directory);
    
    while(fileName != NULL)
    {
        tempString.assign(shaderDirectory);
        tempString.append(fileName->d_name);

        std::cout << tempString << std::endl;

        if(Util::StringLib::endsWith(tempString, ShaderProgram::FileExtension))
        {
            newProgram = new ShaderProgram(&tempString);

            if(newProgram->status == true)
            {
                this->programs.push_back(newProgram);
            }
            else
            {
                delete newProgram;
            }

            fileName = readdir(directory);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Static Stuff:
///////////////////////////////////////////////////////////////////////////////////////////////////
std::string    ShaderManager::shaderDirectory = "./data/shaders/";
ShaderManager* ShaderManager::shaderManager;

ShaderManager* ShaderManager::getShaderManager(void)
{
    return shaderManager;
}

void ShaderManager::init(void)
{
    shaderManager = new ShaderManager();
}

void ShaderManager::uninit(void)
{
    delete shaderManager;
}