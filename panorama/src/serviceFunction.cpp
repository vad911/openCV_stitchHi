#include "serviceFunction.h"
#include <iostream>
#include <string>

void serviceFunction::print_instruction()
{
	std::string str = R"RAW( "using: > panorama  img_01 img_02 ...)RAW";
	std::cout << "\n "<< str << std::endl;
}
