#include "../CLIah.hpp"

#include <iostream>


/* PLAN
	send argv and argc to a function, read each arg. if arg is not recognised
	before one that is, detect and exit.
	
	if arg is one with substr, just copy next arg and push pointer onwards


*/





int main(int argc, char *argv[]) {
	//Add new CLIah structs
	CLIah::addNewArg(
		"Help",                              //Reference
		"--help",                            //Primary match string
		CLIah::ArgType::Flag,                //Argument type
		"-h",                                //Alias match string
		true                                 //Case sensitivity
    );
    
	CLIah::addNewArg(
		"Verbose",                           //Reference
		"--verbose",                         //Primary match string
		CLIah::ArgType::Subcommand,          //Argument type
		"-v",                                //Alias match string
		true                                 //Case sensitivity
    );

	
	

	CLIah::analyseArgs(argc, argv);

	return 0;
}
