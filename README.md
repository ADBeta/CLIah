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
* Support for arbitrary string input
* Definable error messages per argument if it detects a malformed input

----
## How To Use
See the `examples` folder for simple demos of features, and see `doc/Getting Started.md`  
for more detailed information.  

---
## TO-DO
* Function pointers

## Version 3.1.1
Last change:
* Changed getArgByxxxxx to return pointers

## Licence
CLIah is under the GPL (GPL3.0), please see LICENCE for information  
(c) ADBeta 2023
