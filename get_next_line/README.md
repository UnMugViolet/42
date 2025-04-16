# get_next_line

<p align="center">
	<img src="img/get_next_linem.png" alt="Get Next Line Badge" width="15%">
</p>

## Overview
The `get_next_line` project is a coding challenge that involves creating a function capable of reading a line from a file descriptor, one at a time, until the end of the file.

## Features
- Reads a single line from a file descriptor.
- Handles multiple file descriptors simultaneously.
- Efficient memory usage with a customizable buffer size.

## Function Prototype
```c
char *get_next_line(int fd);
```

## Usage
1. Include the `get_next_line.h` header in your project.
2. Compile the source files with your project.
3. Call `get_next_line` with a valid file descriptor.

## Example
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("example.txt", O_RDONLY);
	char *line;

	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

## Notes
- Ensure the buffer size is defined (`BUFFER_SIZE`) during compilation.
- Properly free allocated memory to avoid leaks.

## Testing
Use the provided test files or create your own to validate the function's behavior with various edge cases.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
