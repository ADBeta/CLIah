#include "../CLIah.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
	//Configure the CLIah library
	CLIah::Config::verbose = true; //Set verbosity when match is found
	CLIah::Config::errorMode = CLIah::Config::ErrMode::exit; //Set error mode

	//Add new CLIah Arguments
	CLIah::addNewArg(
		"Help",                              //Reference
		"--help",                            //Primary match string
		CLIah::ArgType::flag,                //Argument type
		"-h",                                //Alias match string
		true                                 //Case sensitivity
    );
    
	CLIah::addNewArg(
		"Verbose",                           //Reference
		"--verbose",                         //Primary match string
		CLIah::ArgType::subcommand,          //Argument type
		"-v",                                //Alias match string
		true                                 //Case sensitivity
    );
	
	//Analyse the argc and argv inputs, to detect what args have been passed
	CLIah::analyseArgs(argc, argv);
	
	std::cout << CLIah::isArgDetected("Verbose") << std::endl;
	std::cout << CLIah::isArgDetected("Help") << std::endl;
	//
	std::cout << std::endl << std::endl;
	
	CLIah::getArgByReference("hello");

	return 0;
}
