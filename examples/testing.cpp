#include "../CLIah.hpp"

#include <iostream>

int main(int argc, char *argv[]) {

	CLIah::Arg test;
	test.argName = "Verbose";
	test.primaryMatchStr = "--verbose";
	test.aliasMatchStr = "-v";


	for(int x = 1; x < argc; x++) {
		std::string inputArg = argv[x];
	
		std::cout << inputArg << "        ";
		
		//TODO Go through all arguments in vector
		
		//Create temporary pointer to the current Arg being tested against
		CLIah::Arg *tempArg = &test;
		
		//TODO if caseSensitive is false, convert both inputArg and tempArg to 
		//uppercase
		
		std::cout << "arg:" << tempArg->argName;
		//Check if argument matches
	
	}
	
	std::cout << std::endl;


	return 0;
}
