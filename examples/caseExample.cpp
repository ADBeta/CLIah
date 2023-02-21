/*******************************************************************************
* This file is part of CLIah, Command Line Interface argument handler.
* If this file is included as part of a seperate project, please see the github
* page for this project: https://github.com/ADBeta/CLIah
*
* This project is under the GPL3.0 licence. (c) 2023 ADBeta
*
* This is a simple Subcommand Argument example
* Modified 17 Feb 2023
*******************************************************************************/

// Compile this example and run it with any iteration of -e or --example
// for example --example --eXaMpLe --EXAMPLE -E or -e

//Change this to whatever your development chain requires
#include "../CLIah.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
	//Configure the CLIah library
	CLIah::Config::verbose = true; //Set verbosity when match is found
	CLIah::Config::stringsEnabled = false; //Disable strings for this example

	//Add new CLIah Arguments
	CLIah::addNewArg(
		"Example",                           //Reference
		"--example",                         //Primary match string
		CLIah::ArgType::subcommand,          //Argument type
		"-e",                                //Alias match string
		false                                //Case sensitivity
    );
	
	//Analyse the argc and argv inputs, to detect what args have been passed
	CLIah::analyseArgs(argc, argv);
	
	std::cout << "Example detected: ";
	if( CLIah::isDetected("Example") == true) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "No" << std::endl;
	} 
	
	return 0;
}
