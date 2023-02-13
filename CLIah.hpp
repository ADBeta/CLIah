/*******************************************************************************
* This file is part of CLIah, Command Line Interface argument handler.
* If this file is included as part of a seperate project, please see the github
* page for this project: https://github.com/ADBeta/CLIah
*
* This project is under the GPL3.0 licence. (c) 2023 ADBeta
*
* Modified 13 Feb 2023
* V 0.2.5
*******************************************************************************/

#include <string>

#ifndef H_CLIAH
#define H_CLIAH

namespace CLIah {


/*** CLI Arg types, structs and variables *************************************/
/* Arg types:
	* Flag is a simple flag like -h or --verbose. No substring is returned
		example --help / -h or -v / --verbose
	* Subcommand is a matched arg with a second string to return as a substring
		example --input hello-world would set substring to hello-world
	* Variable is a type that has an = or - or some other non-text char to get
	  the substring to set
	  	example --value=12 sets substring to 12
*/
enum class ArgType{ Flag, Subcommand, Variable }; 

/*** Error Handling ***********************************************************/


/*** Argument Structure *******************************************************/
//CLI Arg structure
struct Arg {
	//Argument reference name (used to index through all arg objects)
	std::string argReference;

	//Main and secondary (alias) match strings
	std::string priMatchStr = "", aliasMatchStr = "";
	//Is the match string(s) case sensitive
	bool caseSensitive = true;
	
	//What type of argument is this (default to flag)
	ArgType type = ArgType::Flag;
	
	//Function pointer. Executed automatically if match is found TODO
	
	//Return string from sub-command or variable type
	std::string substring; 
	
	//Flag set if the argument has been detected, and validated.
	bool detected = false;
	
}; //struct Arg


}; //namespace CLIah

#endif
