# holbertonschool-simple_shell

Simple Shell
A simple UNIX command interpreter written in C that replicates the basic functionality of /bin/sh.

Description
This project is a simple shell implementation that can execute commands in both interactive and non-interactive modes. It handles command execution, PATH searching, built-in commands, and proper exit status management without using forbidden functions like getenv.

Features
✅ Display a prompt and wait for user input
✅ Execute commands with absolute paths (like /bin/ls)
✅ Execute commands using the PATH environment variable (like ls)
✅ Handle command lines with arguments (like ls -l /tmp)
✅ Implement custom PATH searching without getenv
✅ Handle the exit built-in command with proper exit status
✅ Handle the env built-in command
✅ Handle end-of-file condition (Ctrl+D)
✅ Proper exit status handling (0, 127, etc.)
✅ No memory leaks (Valgrind clean)
✅ No fork called if command doesn't exist
Project Structure
File	Description	Functions
main.h	Header file with function prototypes and includes	N/A
main.c	Main entry point and shell loop	main (1)
shell.c	Core shell functions (prompt, read, parse, free)	display_prompt, read_line, parse_line, free_array (4)
find_path.c	PATH searching without using getenv	get_path_env, find_path (2)
run_command.c	Command execution and process management	fork_and_execute, execute_command (2)
builtin.c	Built-in commands implementation	handle_exit, handle_env, is_builtin (3)
AUTHORS	List of project contributors	N/A
README.md	Project documentation (this file)	N/A
Total: 12 functions across 5 files (max 4 per file ✅)

Key Functions
main.c
main() - Entry point, manages shell loop and exit status

shell.c
display_prompt() - Displays shell prompt $

read_line() - Reads input from user using getline

parse_line() - Parses input into array of arguments

free_array() - Frees allocated memory for argument array

find_path.c
get_path_env() - Gets PATH from environ without getenv

find_path() - Searches for command in PATH directories

run_command.c
fork_and_execute() - Forks and executes command with proper exit status

execute_command() - Main execution logic, returns correct exit codes

builtin.c
handle_exit() - Handles exit command with last exit status

handle_env() - Prints environment variables

is_builtin() - Checks and executes built-in commands

Built-in Commands
Command	Description	Usage
exit	Exit the shell with last command exit status	exit
env	Print all environment variables	env

Technical Details
Memory Management
All allocated memory is properly freed

No memory leaks (verified with Valgrind)

exit command frees all resources before exiting

Process Management
Uses fork() to create child processes

Uses execve() to execute commands

Uses waitpid() to wait for child and get exit status

Uses WIFEXITED() and WEXITSTATUS() macros

PATH Handling
Custom get_path_env() function replaces forbidden getenv()

Searches through environ array directly

Handles empty PATH correctly

Returns NULL for commands not found in PATH

Project Information
This project is part of the Holberton school Software Engineering Program curriculum.

Project: 0x16. C - Simple Shell
Language: C
Standard: gnu89
License
This project is for educational purposes as part of the Holberton school Software Engineering program.
