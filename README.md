# Pipex

This project involves a detailed exploration and programming implementation of a well-known UNIX mechanism. The goal of the **Pipex** project is to create our own version of the pipe functionality commonly used in shells (`|`). This will involve utilizing a new set of functions that introduce concepts such as working with multiple processes, pipes, forks, and duplicating file descriptors.

## About the Project

In this project, the objective is to develop a program that mimics the behavior of the following shell command:

```sh
< file1 cmd1 | cmd2 > file2
```

The program should take an input file (`file1`) and two commands (`cmd1` and `cmd2`), and then execute the following sequence:
1. `file1` is passed as the standard input (`stdin`) to `cmd1`.
2. The output of `cmd1` is piped as the standard input to `cmd2`.
3. The final output is redirected to an output file (`file2`).

Breaking down the command:

- `<`: Denotes that the subsequent argument will serve as the standard input (`stdin`).
- `file1`: Path to the input file, which must exist and be opened read-only.
- `cmd1`: First command that will receive the `stdin` and process it.
- `|`: Redirects the standard output (`stdout`) of the preceding command to the standard input of the next command.
- `cmd2`: Second command that receives the piped input from `cmd1` and processes it.
- `>`: Redirects the standard output (`stdout`) to a file, creating/truncating it if needed.
- `file2`: Path to the output file, which may or may not exist and should be opened write-only.

## The Pipex Algorithm

Our implementation of the above command follows a similar structure. The compiled executable, named `pipex`, expects the following format:

```sh
./pipex file1 cmd1 cmd2 file2
```

This project relies on various tools, including pipes, forks, and duplicating file descriptors (`dup2`). Here's a brief overview of their functions:

- **pipe(fd)**: Opens `fd[0]` for reading and `fd[1]` for writing, allowing communication between processes.
- **fork()**: Creates a child process with a process ID of 0 for the child and a positive process ID for the parent.
- **dup2(oldfd, newfd)**: Duplicates `oldfd` into `newfd`, allowing efficient redirection of file descriptors.
- **execve(path, cmd, envp)**: Replaces the current process with the specified command, parameters, and environment.

## Error Handling & File Descriptor Leaks

This project introduces the concept of file descriptor leaks, where keeping a file open for an extended period can lead to issues. Careful management of file descriptors is essential.

Given that the new functions mentioned earlier can result in errors for various reasons, it's crucial to implement proper error handling. This includes checking for errors with these functions, verifying the existence and permissions of input/output files, and ensuring the availability of the specified commands. Additionally, after a fork, child processes inherit open file descriptors, so it's vital to close unnecessary descriptors within child processes to prevent leaks.

Remember to exercise caution and diligence when handling file descriptors to ensure the reliability and stability of your code.
