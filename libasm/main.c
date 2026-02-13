#include <stdio.h>
#include <libasm.h>
#include <string.h>
#include <errno.h>

void test_ft_write()
{
	char write_str[27] = "Test de la fonction write\n";
	char empty[1] = "";
	char *null_str = NULL;

	printf("Handmade function: \n");
	ft_write(1, &write_str, ft_strlen(write_str));
	printf("Original function: \n");
	write(1, &write_str, strlen(write_str));

	printf("Writing empty str\n");
	ft_write(1, &empty, ft_strlen(empty));
	write(1, &empty, strlen(empty));

	printf("Writing null pointer\n");
	ft_write(1, &null_str, ft_strlen(null_str));
	// write(1, &null_str, strlen(null_str));
	
}


int main(int ac, char **av)
{
	if (ac != 2) {
		printf("Not enough arguments\n");
	} else {
		printf("=========STRLEN===========\n");

		printf("Text: %s\tLen: %zu\n", av[1] ,ft_strlen(av[1]));
		printf("Text: %s\tLen: %zu\n", av[1] , strlen(av[1]));

		printf("=========STRCPY===========\n");

		char dst[6] = "youpi";
		char const cpy[4] = "pip";
		
		printf("Original string: %s", dst);
		printf(" Modified by ft_strcpy: %s\n", ft_strcpy(dst, cpy));

		ft_strcpy(dst, "youpi"); // Reset value

		printf("Original string: %s", dst);
		printf(" Modified by strcpy: %s\n", strcpy(dst, cpy));

		ft_strcpy(dst, "youpi"); // Reset value

		printf("=========STRCMP===========\n");

		printf("Comparing: %s with %s", dst, cpy);
		printf(" Result from ft_strcmp: %i\n", ft_strcmp(dst, cpy));

		printf("Comparing: %s with %s", dst, cpy);
		printf(" Result from strcmp: %i\n", strcmp(dst, cpy));

		printf("=========WRITE===========\n");
		test_ft_write();

	}
	return 0;
}
