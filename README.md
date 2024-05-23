<<<<<<< HEAD
# fifo64_8
Efficient FIFO buffer in C with a capacity of 8 entries, each 8 bytes in size.
=======
# FIFO64_8 Project

## Overview
This project implements a FIFO (First In, First Out) buffer with a capacity of 64 entries, each 8 bytes in size. The implementation is written in C and provides a robust way to handle buffer operations for embedded systems or applications requiring such functionality.

## Files

- `main.c`: The main program file demonstrating the usage of the FIFO buffer.
- `fifo64_8.c`: The source file containing the implementation of the FIFO buffer.
- `fifo64_8.h`: The header file defining the FIFO buffer's interface.
- `Makefile`: A makefile to build the project.
- `.clang-format`: A configuration file for formatting the code according to the specified style.
- `.gitignore`: Specifies files and directories to be ignored by Git.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Make utility

### Building the Project

1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Navigate to the project directory:
   ```bash
   cd <repository-directory>
   ```
3. Build the project using make:
   ```bash
   make
   ```

### Running the Program

After building the project, run the executable:
```bash
./fifo64_8
```

## Code Formatting

The project includes a `.clang-format` file to ensure consistent code style. To format the code, run:
```bash
make format
```

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
>>>>>>> b30e982 (Initial commit)
