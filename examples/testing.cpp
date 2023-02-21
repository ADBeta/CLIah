#include "../CLIah.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
	//Configure the CLIah library
	CLIah::Config::verbose = true; //Set verbosity when match is found
	CLIah::Config::stringsEnabled = true;

	//Add new CLIah Arguments
	CLIah::addNewArg(
		"Help",                              //Reference
		"--help",                            //Primary match string
		CLIah::ArgType::flag,                //Argument type
		"-h",                                //Alias match string
		false                                //Case sensitivity
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
	CLIah::printArg(CLIah::getArgByIndex(0));
	//
	std::cout << CLIah::getSubstring("Verbose") << std::endl << std::endl;
	
	CLIah::getArgByReference("hello");

	return 0;
}
