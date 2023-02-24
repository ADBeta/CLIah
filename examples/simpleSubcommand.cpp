/*******************************************************************************
* This file is part of CLIah, Command Line Interface argument handler.
* If this file is included as part of a seperate project, please see the github
* page for this project: https://github.com/ADBeta/CLIah
*
* This project is under the GPL3.0 licence. (c) 2023 ADBeta
*
* This is a simple Subcommand Argument example
* Modified 24 Feb 2023
*******************************************************************************/

// Compile this example and run it with 
// simpleSubcommand -s or simpleSubcommand --subcommand
// and put another string "command" after it.

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
		"--subcommand",                      //Primary match string
		CLIah::ArgType::subcommand,          //Argument type
		"-s",                                //Alias match string
		true                                 //Case sensitivity
    );
	
	//Set the custom error message when the substring is missing
	CLIah::setErrorMessage("Example", "Demo error message. Substring missing");
	
	//Analyse the argc and argv inputs, to detect what args have been passed
	CLIah::analyseArgs(argc, argv);
	
	std::cout << "Subcommand: " << CLIah::getSubstring("Example") << std::endl;
	
	return 0;
}
