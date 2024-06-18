# get_next_line
## Overview
The get_next_line project is a coding exercise from the 42 School curriculum designed to deepen understanding of file input handling in C. The main goal is to create a function, get_next_line, that reads a file line by line and returns the next line each time it is called. This function must handle different edge cases and work efficiently with a buffer size specified during compilation.
## Features 
- Reads from a file descriptor and returns the next line, including the newline character.
- Manages memory efficiently to avoid leaks.
- Continues reading from where it left off in the file.
- Handles edge cases like empty files, files with no newline characters, and large files.
## Usage

### Function Prototype

```c
char *get_next_line(int fd);
```
### Parameters
``fd``: The file descriptor from which to read.
### Return Value
- Returns the next line from the file descriptor, including the newline character, if one is present.
- Returns NULL if there is nothing more to read or an error occurs.
