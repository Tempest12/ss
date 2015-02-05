#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <time.h>

#include "util/Log.hpp"

//Author Shane del Solar
//Version 2.00.ss

//Namespace this codes belongs to:
using namespace Util;

static int currentLevel;
static bool status;
static std::ofstream file;
static std::chrono::system_clock::time_point currentTime;

static const std::string debugPrefix   = "  DBUG                     : ";
static const std::string infoPrefix    = "       INFO                : ";
static const std::string errorPrefix   = "            EROR           : ";
static const std::string fatalPrefix   = "                 FTAL      : ";
static const std::string specialPrefix = "                      SPCL : ";

bool Log::init(bool append, int level)
{
    currentLevel = level;

    if(append)
    {
        file.open("log.txt", std::ofstream::app);    
    }
    else
    {
        file.open("log.txt", std::ofstream::trunc);
    }
    
    if(file.is_open())
    {
        status = file.good();

        if(status)
        {
            writeMessage("Log ", "Opened.");            
        }
    }

    return file.good();
}

void Log::setLevel(LogLevel nextLevel)
{
    currentLevel = nextLevel;
}

void Log::writeAt(LogLevel level, const std::string& message)
{
    switch(level)
    {
        case DEBUG:
            writeDebug(message);
            break;

        case INFO:
            writeInfo(message);
            break;

        case ERROR:
            writeError(message);
            break;

        case FATAL:
            writeFatal(message);
            break;

        case SPECIAL:
            writeSpecial(message);
            break;

        default:
            std::stringstream temp;
            temp << level;

            writeError("Unknown log level requested: " + temp.str() + " message requested was: \"" + message + "\".");
            break;
    }
}

void Log::writeDebug(const std::string& message)
{
    if(currentLevel <= (int)DEBUG)
    {
        writeMessage(debugPrefix, message);
    }
    
    std::cout << message << std::endl;
}

void Log::writeInfo(const std::string& message)
{
    if(currentLevel <= (int)INFO)
    {
        writeMessage(infoPrefix, message);
    }
    
    std::cout << message << std::endl;
}

void Log::writeError(const std::string& message)
{
    if(currentLevel <= (int)ERROR)
    {
        writeMessage(errorPrefix, message);
    }
    
    std::cout << message << std::endl;
}

void Log::writeFatal(const std::string& message)
{
    if(currentLevel <= (int)FATAL)
    {
        writeMessage(fatalPrefix, message);
    }
    
    std::cout << message << std::endl;
}

void Log::writeSpecial(const std::string& message)
{
    writeMessage(specialPrefix, message);
    std::cout << message << std::endl;
}

void Log::writeMessage(const std::string& prefix, const std::string& message)
{
    currentTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    std::string timeString = std::string(std::ctime(&time));

    if(file.is_open() && status)
    {
        file << timeString.substr(0, timeString.length() - 1) << " " << prefix << message << std::endl;
        status = file.good();
    }
}

void Log::uninit(void)
{
    if(file.is_open() && status)
    {
        writeMessage("Log ", "Closed.");

        file.close();
    }
} 
