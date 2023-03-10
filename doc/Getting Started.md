There are detailed examples in the `examples` directory, but here is a breif tutorial:  
To add a new Argument to CLIah's 'database'  
```C++
CLIah::addNewArg(
	"Help",                              //Reference
	"--help",                            //Primary match string
	CLIah::ArgType::flag,                //Argument type
	"-h",                                //Alias match string
	true                                 //Case sensitivity
); 
```

You can add a custom error message using  
```C++
CLIah::setErrorMessage("Example", "Demo error message. Substring missing");

```

To configure the CLIah library you can use  
`CLIah::Config::verbose = true/false` To enable/disable verbose output.  
and  
`CLIah::Config::stringsEnabled = true/false` To define if CLIah will treat an  
undefined Arg string as an error and exit, or if it will copy it to a String  
struct vector (like the Arg vector) for use by the programmer. 

To scan and analyse the arguments passed via the command line, use  
`CLIah::analyseArgs(argc, argv);`  
and all the error handling, subcommand, variable etc will be done for you.  
**This must be done before any calls to the CLIah Argument or String functions**

To check if an argument has been detected, and to get the substring there are  
two options. The recommended method is to use the built-in functions, passing  
the Reference name string.
```C++
bool detected = CLIah::isDetected("example");

if (detected) {
	//Do something
}
```
and  
```C++
std::string substring = CLIah::getSubstring("example");

std::cout << substring << std::endl;
```


The other method is to create a new Arg Object and use `getArgByReference(string)`  
or `getArgByIndex(int)`, like this.  
```C++
CLIah::Arg *example = CLIah::getArgByReference("example");
//or
CLIah::Arg *example = CLIah::getArgByIndex(0);

if (example->detected) {
	//Do Something
}

std::cout << example->substring << std::endl;
```

This is not highly recommended as it removes a lot of the abstraction that CLIah  
provides, but it is perfectly valid if some specific use is required.  

To allow CLIah to take arbitrary strings, enable them with a config flag.  
You can then pull the strings from the stringVector or built-in methods:
```C++
CLIah::Config::stringsEnabled = true; //Enable arbitrary strings

//Request a stringVector by the index it appeared in the Command Line (0 index)
CLIah::String *stringObj = CLIah::getStringByIndex(0);
std::cout << "Gotten by index: " << stringObj->string << std::endl;

//Directly access a specific stringVector object (Be careful of requesting past
//the end of the vector)
std::cout << "Direct Access: " << CLIah::stringVector[0].string << std::endl;

//Loop through all objects in the stringVector 
CLIah::String stringLoop;
for(size_t index = 0; index > stringVector.size(); index++) {
	stringLoop = stringVector.at(index);
	std::cout << stringLoop.string << std::endl;
}
```
