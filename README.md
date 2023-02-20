# CLIah
**C**ommand **L**ine **I**nterface **a**rgument **h**andler  

## Description
CLIah is a C++ Library header to allow for easy Command Line Argument parsing,  
validation and execution. Instead of manually handling the CLI arguments, define  
CLIah Arg structures and pass argv & argc.  

CLIah supports a wide range of arguments, parsing methods, and execution style:  
* Multiple argument types eg. flags, variables and sub-commands.  
* Argument string, plus one additional alias string (--verbose alias -v)  
* Definable function pointers to automate execution if a CLI Argument is matched (not in beta)  
* Multiple unrecognised arg failmodes - Exit, Warn and Ignore  

## How To Use
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
the Reference name strings to...
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


The other method is to create a new Arg Object and use `getArgByReference`, like this.  
```C++
CLIah::Arg example = getArgByReference("example");

if (example.detected) {
	//Do Something
}

std::cout << example.substring << std::endl;
```

This is not highly recommended as it removes a lot of the abstraction that CLIah  
provides, but it is perfectly valid if some specific use is required.  

---

## TO-DO 
* Overloadable error function or string, executed when unknown argument is passed
* Function pointers
* strToUpper externalised ?????

## Version 1.0.0

## Licence
CLIah is under the GPL (GPL3.0), please see LICENCE for information  
(c) ADBeta 2023
