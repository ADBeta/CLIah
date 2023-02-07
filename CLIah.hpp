/*******************************************************************************
* This file is part of CLIah, Command Line Interface argument handler.
* If this file is included as part of a seperate project, please see the github
* page for this project: https://github.com/ADBeta/CLIah
*
* This project is under the GPL3.0 licence. (c) 2023 ADBeta
*
* Modified 07 Feb 2023
* V 0.1.1
*******************************************************************************/

#include <string>

#ifndef H_CLIAH
#define H_CLIAH

namespace CLIah {


/*** CLI Arg types, structs and variables *************************************/
//Arg types
enum class ArgType{ Flag, Subcommand, Variable, String }; 

/*** Error Handling ***********************************************************/


/*** Argument Structure *******************************************************/
//CLI Arg structure
struct Arg {
	//Argument name (used to index through all arg objects)
	std::string argName;

	//Main and secondary (alias) match strings
	std::string primaryMatchStr = "", aliasMatchStr = "";
	//Is the match string(s) case sensitive
	bool caseSensitive = true;
	
	ArgType type = ArgType::Flag; //What type of argument is this (default to flag)
	
	//Function pointer. Executed automatically if match is found TODO
	
	//Return string from sub-command or variable type
	std::string variableStr; 
	
	//Flag set if the argument has been detected, and validated.
	bool detected = false;
	
}; //struct Arg


}; //namespace CLIah



#endif
