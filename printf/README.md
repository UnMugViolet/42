# ft_printf

<p align="center">
	<img src="img/ft_printfe.png" alt="ft_printf Badge" width="15%">
</p>

## Introduction

`ft_printf` is a custom implementation of the standard `printf` function in C. This project is part of the 42 curriculum and aims to deepen understanding of variadic functions, formatted output, and overall C programming skills.

## Features

- Handles the following conversions:
	- `%c` - Character
	- `%s` - String
	- `%p` - Pointer address
	- `%d` - Decimal integer
	- `%i` - Integer
	- `%u` - Unsigned integer
	- `%x` - Hexadecimal (lowercase)
	- `%X` - Hexadecimal (uppercase)
	- `%%` - Percent sign
- There is an improved version of ft_printf handling more cases on the <a href="https://github.com/UnMugViolet/libft">libft repository</a>
- A `ft_fprintf` handling standard output is also available on the libft
## Usage

1. Clone the repository:
	 ```bash
	 git clone https://github.com/your_username/ft_printf.git
	 cd ft_printf
	 ```

2. Compile the library:
	 ```bash
	 make
	 ```

3. Include `libftprintf.a` in your project:
	 ```bash
	 cc -Wall -Wextra -Werror your_file.c -L. -lftprintf
	 ```

4. Use `ft_printf` in your code:
	 ```c
	 #include "ft_printf.h"

	 int main(void)
	 {
			 ft_printf("Hello, %s!\n", "world");
			 return (0);
	 }
	 ```

## Files

- `ft_printf.c` - Main function handling formatted output.
- `ft_printf_utils.c` - Utility functions for formatting.
- `libft` - Custom library used for string and memory manipulation.

## Testing

You can test the functionality of `ft_printf` by comparing its output to the standard `printf`. Use the provided test cases or create your own.

## Credits

This project was completed as part of the 42 curriculum. For more information, visit [42 Network](https://www.42.fr/).

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

