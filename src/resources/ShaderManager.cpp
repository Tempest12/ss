#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <dirent.h>

#include "main/Main.hpp"
#include "resources/Shader.hpp"
#include "resources/ShaderProgram.hpp"
#include "resources/ShaderManager.hpp"
#include "util/Config.hpp"
#include "util/StringLib.hpp"

using namespace Resources;

ShaderManager::ShaderManager(void)
{
    this->shaders  = std::vector<Shader*>();
    this->programs = std::vector<ShaderProgram*>(); 
    
    
    this->loadShaders();
    this->loadPrograms();
    
    
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
    DIR* directory = opendir("./data/shaders");
    struct dirent* fileName;
    Shader* newShader;
    
    if(directory == NULL)
    {
        Main::die("Unable to open shader directory .");
    }
    
    fileName = readdir(directory);
    
    while(fileName != NULL)
    {
        newShader = new Shader(fileName->d_name);
        
        if(newShader->type != INVALID)
        {
            this->shaders.push_back(newShader);
        }
        else
        {
            delete newShader;
        }
        
        fileName = readdir(directory);
    }
}

void ShaderManager::loadPrograms(void)
{
    DIR* directory = opendir("./data/shaders");
    struct dirent* fileName;
    ShaderProgram* newProgram;
    
    if(directory == NULL)
    {
        Main::die("Unable to open shader directory .");
    }
    
    fileName = readdir(directory);
    
    while(fileName != NULL)
    {
        newProgram = new ShaderProgram(fileName->d_name);
        
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

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Static Stuff:
///////////////////////////////////////////////////////////////////////////////////////////////////
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
