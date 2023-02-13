#include "../CLIah.hpp"

#include <iostream>


/* PLAN
	send argv and argc to a function, read each arg. if arg is not recognised
	before one that is, detect and exit.
	
	if arg is one with substr, just copy next arg and push pointer onwards


*/

CLIah::Arg test;


void analyse(int argc, char *argv[]) {
	//Regular argc and argv should have been passed. Adjust to remove argv[0]
	--argc;
	++argv;

	//Go through every element in argv
	for(int argStrIdx = 0; argStrIdx < argc; argStrIdx++) {
		//Convert curent argv char[] to string
		std::string inputArg = argv[argStrIdx];
	
		std::cout << "input: " << inputArg << std::endl;
		
		//Create a temp pointer to the current Arg being tested for
		CLIah::Arg *tempArg = &test;
		
		//Compare the primary and alias arg string to input. Store results
		int priMatch, aliasMatch;
		priMatch = tempArg->priMatchStr.compare(inputArg);
		aliasMatch = tempArg->aliasMatchStr.compare(inputArg);
		
		/* NOTE: Leaving primary vs alias detection as possilbe independant 
		triggers as this may be useful in the future for some niche cases     */
		if(priMatch == 0 || aliasMatch == 0) {
			
			
			std::cout << "matched reference: " << tempArg->argReference << std::endl;
			
			/*** Arg Type detection *******************************************/
			//Get the matched argument type to do specific execution.
			CLIah::ArgType tempType = tempArg->type;
			
			//If the detected Arg is a Flag Type, just set detected and continue
			if(tempType == CLIah::ArgType::Flag) {
				std::cout << "flag set" << std::endl;
				tempArg->detected = true;
			}
			
			//If the Arg is Subcommand type, get the next inputArg string
			//set the substring of the main object
			if(tempType == CLIah::ArgType::Subcommand) {
				//make sure there *IS* a next argument, if not error.
				if(argStrIdx + 1 >= argc) {
					std::cout << "error, no extra command for subcommand" << std::endl;
					exit(EXIT_FAILURE);
				}
				
				//Incriment argStrIdx by one, to get the next arg string, then
				//the next loop will skip past it.
				++argStrIdx;
				tempArg->substring = argv[argStrIdx];
				
				std::cout << "substr: " << tempArg->substring << std::endl;
				tempArg->detected = true;
			}
			
			//TODO Variable type
			
		}
		
	
	}

}



int main(int argc, char *argv[]) {

	test.argReference = "Verbose";
	test.priMatchStr = "--verbose";
	test.aliasMatchStr = "-v";
	
	test.type = CLIah::ArgType::Subcommand;

	analyse(argc, argv);

	return 0;
}
