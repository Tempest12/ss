#include <iostream>
#include <string>

#include <GL/freeglut.h>

#include "core/GLCore.hpp"
#include "main/Main.hpp"
#include "util/Log.hpp"

int main(int argc, char** argv)
{
	int result = 0;

	Core::GLCore::init(argc, argv);

	//glutMainLoop();

	return result;	
}

void Main::die(const std::string& errorMessage)
{
	Util::Log::writeFatal(errorMessage);
	std::cout << "Exiting" << std::endl;

	exit(1);
}