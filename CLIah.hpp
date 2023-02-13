/*******************************************************************************
* This file is part of CLIah, Command Line Interface argument handler.
* If this file is included as part of a seperate project, please see the github
* page for this project: https://github.com/ADBeta/CLIah
*
* This project is under the GPL3.0 licence. (c) 2023 ADBeta
*
* Modified 13 Feb 2023
* V 0.2.8
*******************************************************************************/

#include <string>
#include <vector>

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
	
	/*** Detection variables. Not user modifiable ***/
	//private:
	
	//Return string from sub-command or variable type
	std::string substring; 
	//Flag set if the argument has been detected, and validated.
	bool detected = false;
	
}; //struct Arg

//Vector array of Args, stores user defined Args & variables therin
extern std::vector <Arg> argVector;

/*** CLIah functions **********************************************************/
//Skims all arguments passed via cli and sets internal struct vars.
//Must be called before any other functions can be.
void analyseArgs(int argc, char *argv[]);

//Pushes a new argument to the argVecor. Some variables are mandatory:
// argReference		- String by which the argument is known. eg verbose
// priMatchStr		- String to match for a detection (alias is optional)
// argType			- The type of the argument, see ArgType for info
void addNewArg(std::string argReference, std::string priMatchStr, ArgType type,
               std::string aliasMatchStr, bool caseSensitive);

//Finds and statically returns Arg struct with searched argReference string.
//TODO

}; //namespace CLIah

#endif
