/*******************************************************************************
* This file is part of CLIah, Command Line Interface argument handler.
* If this file is included as part of a seperate project, please see the github
* page for this project: https://github.com/ADBeta/CLIah
*
* This project is under the GPL3.0 licence. (c) 2023 ADBeta
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "CLIah.hpp"

/*** CLIah Functions **********************************************************/
namespace CLIah {
std::vector <Arg> argVector;

void analyseArgs(int argc, char *argv[]) {
	//Regular argc and argv should have been passed. Adjust to remove argv[0]
	--argc;
	++argv;

	//Create iterator for argVector for looping later
	std::vector<Arg>::iterator itrtr; 

	//Go through every element in the argv array
	for(int argStrIdx = 0; argStrIdx < argc; argStrIdx++) {
		//Convert curent argv char[] to string
		std::string inputArg = argv[argStrIdx];
	
		std::cout << "input: " << inputArg << std::endl;
		
		//Loop through all Args stored in argVector. Use iterator as temp object
		for(itrtr = argVector.begin(); itrtr != argVector.end(); itrtr++) {
			
			std::cout << "arg: " << itrtr->argReference << std::endl;
		
			
			//Compare the primary and alias arg string to input. Store results
			int priMatch, aliasMatch;
			priMatch = itrtr->priMatchStr.compare(inputArg);
			aliasMatch = itrtr->aliasMatchStr.compare(inputArg);
			
			/* NOTE: Leaving primary vs alias detection as possilbe independant 
			triggers as this may be useful in the future for some niche cases */
			if(priMatch == 0 || aliasMatch == 0) {
				
				std::cout << "matched reference: " << itrtr->argReference << std::endl;
				
				/*** Arg Type detection ***************************************/
				//Get the matched argument type to do specific execution.
				CLIah::ArgType tempType = itrtr->type;
				
				//If the Arg is a Flag Type, just set detected and continue
				if(tempType == CLIah::ArgType::Flag) {
					std::cout << "flag set" << std::endl;
					itrtr->detected = true;
				}
				
				//If the Arg is Subcommand type, get the next inputArg string,
				//set the substring of the main object
				if(tempType == CLIah::ArgType::Subcommand) {
					//Make sure there *IS* a next argument, if not error.
					if(argStrIdx + 1 >= argc) {
						std::cout << "error, no extra command for subcommand" << std::endl;
						exit(EXIT_FAILURE);
					}
					
					//Incriment argStrIdx by one, to get the next arg string, then
					//the next loop will skip past it.
					++argStrIdx;
					itrtr->substring = argv[argStrIdx];
					
					std::cout << "substr: " << itrtr->substring << std::endl;
					itrtr->detected = true;
				}
				
				//TODO Variable type		
			}
		}
		std::cout << std::endl << std::endl;
	}
}

void addNewArg(std::string ref, std::string pri, ArgType type,
                      std::string alias = "", bool caseSensitive = true) {
	//Create an Arg object to set the parameters to
	Arg newArg;
	
	//Set the new args variables
	newArg.argReference = ref;
	newArg.priMatchStr = pri;
	newArg.type = type;
	newArg.aliasMatchStr = alias;
	newArg.caseSensitive = caseSensitive;
	
	//Push the new argument to the argVector
	argVector.push_back(newArg);
}

Arg getArgByReference(std::string reference) {
	static Arg retArg;
	
	//Go through every argVector element and check for reference string
	std::vector<Arg>::iterator itrtr; 
	for(itrtr = argVector.begin(); itrtr != argVector.end(); itrtr++) {
		//Compare reference string and argReference. 
		if(reference.compare( itrtr->argReference ) == 0) {
			//Set the return Arg object pointer, and return it
			retArg = *itrtr;
			return retArg;
		}
	}
	
	//If no match is found, exec error routine. could just warn and continue TODO
	std::cout << "Err, no reference match found" << std::endl;
	
	return retArg;
}

bool isArgDetected(std::string reference) {
	//Get the Arg by reference and assign it to an Arg object
	Arg tempArg = getArgByReference(reference);
	
	return tempArg.detected;
}

} //namespace CLIah
