# Get Next Line - Reading a line from a file descriptor is way too tedious

This project aims to develop a function, `get_next_line()`, which reads a line from a file descriptor. It provides an opportunity to learn about static variables in C programming.

## Summary
### Mandatory Part

The `get_next_line()` function reads a line from a file descriptor and returns it.

| Function     | Prototype                     | Description                                         |
|--------------|-------------------------------|-----------------------------------------------------|
| get_next_line| `char *get_next_line(int fd)` | Reads a line from the file descriptor `fd`.         |

### Bonus Part

If the mandatory part is perfect, attempt the bonus part which involves:
- Developing `get_next_line()` using only one static variable.
- Managing multiple file descriptors simultaneously.
Append the `_bonus` suffix to bonus part files.

## Usage

- Clone the repository.
- Compile the project using the provided Makefile.
- Include `get_next_line.h` in your C projects to access the `get_next_line()` function.
