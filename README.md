# Holberton School Simple Shell
## Basic linux command line interpreter
 ![Alt Text](https://media.giphy.com/media/lQO3dG0scKkkRAY5GN/giphy.gif)
### Includes all linux executables plus 3 built-ins:
- `cd`
- `env`
- `exit`

### How it works?
Takes an argument provided by the user from the standard input and applicates to it these 3 steps:

[Interpretation](#interpretation) 

[Tokenization](#tokenization) 

[Execution](#execution)

- ### Interpretation
Reads the input from the user with getline function and stores into an array of tokens
- ### Tokenization
Separates the complete input "string" into separate tokens (with help of a specified deilimiter) in order to handle command flags <span>

- ### Execution:
Manages the tokenized given argument and compares it with an existing directory (using stat function) in case of a built-in it calls the corresponding function <span>

## Used Functionns

 - `_strlen`
- `getenv`
- `_strcmp`
- `_strcat`
- `strncmp`
- `printf`
- `strtok`
- `strtol`
- `memset`
- Also `malloc`, and `free` were used for memory allocation.

## System calls
**execve**:
Executes the program referred to by pathname. <br> This causes the program that is currently being run by the calling process to be replaced with a new program.

**exit**:
Terminate the calling process (in this case with predefined macros) 0 success ,1 failure.

**fork**:
Used to create processes. It takes no arguments and returns a process ID. 
The purpose of fork() is to create a new process, which becomes the child process of the caller. 

**wait**:
Suspends execution of the current process until one of its children terminates.

**stat**:
Displays file or file system status.

## Installation
1. Clone this repo [here](https://github.com/brncd/holbertonschool-simple_shell)
2. Compile the code: ```gcc *. -o simple_shell```
  
## Authors
- [Agustin3100](https://github.com/Agustin3100)
- [brnc](https://github.com/brncd)
