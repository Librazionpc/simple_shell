# Simple Shell

## Introduction
The Simple Shell is a basic Unix-like command-line interface designed to emulate some of the core features of the Bash shell. This project serves as a learning exercise to gain insights into shell programming and how commands are executed within a Unix-like environment.

## What is a Shell?
A **shell** is a command-line interface that provides users with a way to interact with the operating system. It acts as an intermediary between the user and the kernel of the operating system, allowing users to run commands, manage files, and perform system tasks. Shells interpret user commands and translate them into instructions that the operating system can execute.

### Types of Shells
There are several types of shells available, including:

- **Bourne Shell (sh):** The original Unix shell created by Stephen Bourne.
- **Bash (Bourne-Again Shell):** The most common shell on Linux systems, extending the features of the Bourne Shell.
- **C Shell (csh):** Known for its C-like syntax.
- **Korn Shell (ksh):** Developed as an enhancement to the Bourne Shell.
- **Z Shell (zsh):** An extended Bourne Shell with many additional features.
- **Fish:** A user-friendly shell with a focus on interactive use.

## Features
Our Simple Shell currently offers the following essential features:

1. **Command Execution:** You can run external commands by typing their names, just like in a standard shell.

2. **Built-in Commands:** We have implemented a few built-in commands, including:
   - `cd` (Change Directory): Change the current working directory.
   - `exit`: Exit the shell gracefully.

3. **Path Resolution:** The shell searches for executable files in directories listed in the `PATH` environment variable. You can specify the complete path to execute a command from anywhere.

4. **Input and Output Redirection:** Redirect standard input (`stdin`) and standard output (`stdout`) using the `<` (input redirection) and `>` (output redirection) operators, respectively.

5. **Piping:** Chain multiple commands together using the `|` (pipe) operator to pass the output of one command as input to another.

6. **Error Handling:** The shell provides basic error handling and reports errors to the user.

7. **Interactive and Batch Mode:** You can run the shell interactively or provide a script file for batch processing.

## Shell Scripting
Shell scripting is the process of writing and executing scripts (sequences of commands) in a shell to automate tasks and perform system administration. Shell scripts are plain text files containing a series of commands that the shell executes one after the other.

Key elements of shell scripting include:

- **Shebang:** A special line at the beginning of a script that specifies the interpreter to use (e.g., `#!/bin/bash` for Bash).

- **Variables:** You can define and use variables to store and manipulate data.

- **Conditional Statements:** Shell scripts support conditional statements like `if`, `elif`, and `else` for decision-making.

- **Loops:** You can use loops such as `for` and `while` to repeat commands multiple times.

- **Functions:** Organize your code into reusable functions for better maintainability.

- **Command Line Arguments:** Access and process command-line arguments passed to the script.

## Getting Started
To use the Simple Shell, follow these steps:

1. Clone this repository to your local machine:
   ```shell
   git clone https://github.com/yourusername/simple-shell.git
