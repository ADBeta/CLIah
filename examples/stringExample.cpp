#include "../CLIah.hpp"

#include <iostream>

//Run this example and pass whatever strngs you want, this example will detect
//them and loop through all of them while printing them out

int main(int argc, char *argv[]) {
	//Configure the CLIah library
	CLIah::Config::verbose = true; //Set verbosity when match is found
	CLIah::Config::stringsEnabled = true; //Enable strings for this example

	//No CLIah Args are needed for strings to work
	
	//Analyse the argc and argv inputs, to detect the strings. This will print 
	//them out by default
	CLIah::analyseArgs(argc, argv);

	//To go through each string in the vector (index based loop. works with
	//iterators too
	for(size_t str = 0; str < CLIah::stringVector.size(); str++) {
		CLIah::String obj = CLIah::stringVector.at(str);
		
		std::cout << obj.string << std::endl;
	}

	return 0;
}
