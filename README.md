Holberton Simple Shell

A simple UNIX command interpreter written in C that replicates the basic functionality of /bin/sh.
It supports interactive and non-interactive modes, command execution, custom PATH searching, and built-in commands.

Table of Contents

Description

Features

Project Structure

Key Functions

Built-in Commands

Technical Details

Project Information

Description

This project implements a simple shell capable of executing commands in UNIX.
It parses user input, searches for executables in the system PATH, manages processes, and handles built-in commands like exit and env.

The shell is designed without using forbidden functions such as getenv() and ensures proper memory management.

Features ✅

Display a shell prompt $ and wait for user input.

Execute commands with absolute paths (e.g., /bin/ls).

Execute commands using the PATH environment variable (e.g., ls).

Support command lines with arguments (e.g., ls -l /tmp).

Custom PATH searching without using getenv().

Implement exit built-in command with proper exit status.

Implement env built-in command to print environment variables.

Handle end-of-file (Ctrl+D) gracefully.

Proper exit status handling (0, 127, etc.).

No memory leaks (Valgrind clean).

Project Structure
File	Description	Functions
main.h	Header file with function prototypes and includes	N/A
main.c	Main entry point and shell loop	main
shell.c	Core shell functions (prompt, read, parse, free)	display_prompt, read_line, parse_line, free_array
find_path.c	Custom PATH searching without using getenv	get_path_env, find_path
run_command.c	Command execution and process management	fork_and_execute, execute_command
builtin.c	Built-in commands implementation	handle_exit, handle_env, is_builtin
README.md	Project documentation	N/A

Total: 12 functions across 5 files (max 4 per file ✅)

Key Functions
main.c

main() – Entry point; manages shell loop and exit status.

shell.c

display_prompt() – Shows shell prompt $.

read_line() – Reads user input.

parse_line() – Parses input into argument array.

free_array() – Frees memory allocated for argument array.

find_path.c

get_path_env() – Gets PATH from environ without getenv.

find_path() – Searches for a command in PATH directories.

run_command.c

fork_and_execute() – Forks a child process and executes a command.

execute_command() – Main execution logic; returns proper exit codes.

builtin.c

handle_exit() – Handles exit command with last exit status.

handle_env() – Prints environment variables.

is_builtin() – Checks and executes built-in commands.

Built-in Commands
Command	Description	Usage
exit	Exit the shell with last command exit status	exit
env	Print all environment variables	env
Technical Details
Memory Management

All allocated memory is properly freed.

No memory leaks (verified with Valgrind).

exit command frees all resources before exiting.

Process Management

Uses fork() to create child processes.

Uses execve() to execute commands.

Uses waitpid() to wait for child and retrieve exit status.

Handles exit codes using WIFEXITED() and WEXITSTATUS().

PATH Handling

Custom get_path_env() replaces forbidden getenv().

Searches through the environ array directly.

Handles empty PATH correctly.

Returns NULL if command not found in PATH.

Project Information

Holberton School Software Engineering Program

Project: 0x16. C - Simple Shell

Language: C

C Standard: gnu89

License: Educational purposes only
