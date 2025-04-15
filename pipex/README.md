# Pipex

<p align="center">
	<img src="img/pipexm.png" alt="Pipex Badge" width="15%">
</p>

## Introduction

The **Pipex** project is part of the 42 curriculum and focuses on understanding and implementing UNIX system calls, particularly those related to process creation, pipes, and file redirection. The goal is to recreate the behavior of the shell's pipe (`|`) operator.

## Objectives

The project aims to deepen your understanding of:
- Process creation and management using `fork`.
- Inter-process communication using pipes.
- File redirection using `dup2`.
- Error handling and edge case management.

## Mandatory Part

You will implement a program that mimics the behavior of the following shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

Your program should:
1. Take four arguments:
	- `file1`: The input file.
	- `cmd1`: The first command to execute.
	- `cmd2`: The second command to execute.
	- `file2`: The output file.
2. Redirect the input and output as specified.
3. Use pipes to connect the output of `cmd1` to the input of `cmd2`.

### Usage

```bash
./pipex file1 "cmd1" "cmd2" file2
```

Example:

```bash
./pipex infile "ls -l" "wc -l" outfile
```

This should produce the same result as:

```bash
< infile ls -l | wc -l > outfile
```

## Bonus Part

For the bonus part, you can extend the functionality to handle:
- Multiple pipes (e.g., `./pipex infile cmd1 cmd2 cmd3 outfile`).
- `here_doc` functionality for handling heredoc input.

### Bonus Usage

```bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

## Allowed Functions

You are allowed to use the following system calls and functions:
- `open`, `close`, `read`, `write`
- `malloc`, `free`
- `perror`, `strerror`
- `dup`, `dup2`
- `pipe`
- `fork`, `execve`
- `wait`, `waitpid`
- `access`, `unlink`

## Evaluation

Your implementation will be evaluated based on:
- Correctness of the program's behavior.
- Proper error handling.
- Code readability and structure.
- Adherence to the project requirements.
- No memory leaks
- No segmentation faults

## Conclusion

The **Pipex** project is an excellent opportunity to dive deeper into UNIX programming and understand the inner workings of shell pipelines.

## License
This project is licensed under the MIT License.
