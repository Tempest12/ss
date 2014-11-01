#include <fstream>
#include <string>
#include <vector>

#include "main/Main.hpp"
#include "util/Parsing.hpp"
#include "util/StringLib.hpp"

using namespace Util;

void Parsing::getNewLine(std::ifstream* file, std::string* line, int* lineNumber)
{
	std::getline(*file, *line);
	StringLib::trim(line);

	if(lineNumber != NULL)
	{   
	    (*lineNumber)++;
	}
}

std::vector<std::string*>* Parsing::getStringArray(std::string* fileName)
{
    std::vector<std::string*>* array = new std::vector<std::string*>();
    std::ifstream file;
    std::string line;
    
    int lineNumber = 0;
    
    file.open(*fileName, std::ifstream::in);
    
    if((file.is_open() && file.good()) == false)
    {
        Main::die("Parsing:  Unable to open file: " + *fileName);    
    }
    
    while(file.good())
    {
        Parsing::getNewLine(&file, &line, &lineNumber);
        
        if(StringLib::isWhiteSpace(line) || line[0] == '#' || (line[0] == '/' && line[1] == '/'))
		{
			continue;
		}
		else
		{
		    array->push_back(new std::string(line));
		}
    }
    
    return array;
}
