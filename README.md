# <h1 align = "center" > Holberton School Simple Shell
## <h2 align = "center"> Basic Copy of SH linux command line interpreter
  ![Alt Text](https://media.giphy.com/media/lQO3dG0scKkkRAY5GN/giphy.gif)
  <img src="https://i.imgur.com/7h7QE8Q.jpg" width="500" height="268" />
## Includes all linux executables plus 3 built-ins <span> :
#### Cd, env, exit (See man for more info)
#### How it works?
#### Takes an argument provided by the user from the standard input and applicates to it these 3 steps:

[Interpretation](#interpretation) <li><code>getline</code> (man 3 getline)</li>

[Tokenization](#tokenization) <li><code>strtok</code> (man 3 strtok)</li>

[Execution](#execution) <li><code>execve</code> (man 2 execve)</li>

 <h3 align = center> See system calls


# Interpretation


## Reads the input from the user with getline function and stores into an array of tokens


# Tokenization

## Separates the complete input "string" into separate tokens (with help of a specified deilimiter) in order to handle command flags <span>
# Execution:
## Manages the tokenized given argument and compares it with an existing directory (using stat function) in case of a built-in it calls the corresponding function <span>

# <h2 align = "center"> Used Functionns

## _strlen  [See code](https://github.com/Agustin3100/holbertonschool-low_level_programming/blob/master/pointers_arrays_strings/2-strlen.c)
## getenv [Standard](https://man7.org/linux/man-pages/man3/getenv.3.html) <img align=right src="https://i.imgur.com/WZAROXj.jpg" width="400" height="368" />
## _strcmp [See code](https://github.com/Agustin3100/holbertonschool-low_level_programming/blob/master/pointers_arrays_strings/3-strcmp.c)
## _strcat [See code](https://github.com/Agustin3100/holbertonschool-low_level_programming/blob/master/pointers_arrays_strings/0-strcat.c) 
## strncmp [Standard](https://linux.die.net/man/3/strncmp)  
## printf [Standard](https://man7.org/linux/man-pages/man3/printf.3.html)
## strtok [Standard](https://man7.org/linux/man-pages/man3/strtok_r.3.html)
## strtol [Standard](https://man7.org/linux/man-pages/man3/strtol.3.html)
## memset [Standard](https://man7.org/linux/man-pages/man3/memset.3.html)
## Also malloc, and free were used for memory allocation
  
# <h2 align = center> System calls
## <summary> execve -  executes the program referred to by pathname. <br> This causes the program that is currently being run by the calling process to be replaced with a new program.
## <summary> exit - terminate the calling process (in this case with predefined macros) 0 success ,1 failure.
## <summary> fork - used to create processes. It takes no arguments and returns a process ID. <br> The purpose of fork() is to create a new process, which becomes the child process of the caller. 
## <summary> wait - suspends execution of the current process until one of its children terminates.
## <summary> stat - displays file or file system status.
# Installation
## Clone this repo [here](https://github.com/brncd/holbertonschool-simple_shell)
  
## Authors
### [Agustin Perez Hornos](https://github.com/Agustin3100)
### [Bruno Carnales](https://github.com/brncd)
