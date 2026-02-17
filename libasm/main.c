#include <stdio.h>
#include <libasm.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

void test_ft_write()
{
	char write_str[27] = "Test de la fonction write\n";
	char empty[1] = "";

	printf("Handmade function: \n");
	ft_write(1, &write_str, ft_strlen(write_str));
	printf("Original function: \n");
	write(1, &write_str, strlen(write_str));

	printf("Writing empty str\n");
	ft_write(1, &empty, ft_strlen(empty));
	write(1, &empty, strlen(empty));

	// Uncomment will segfault for the original function and the Assembly function
	// char *null_str = NULL;
	// 
	// printf("Writing null pointer\n");
	// ft_write(1, &null_str, ft_strlen(null_str));
	// write(1, &null_str, strlen(null_str));
}

void test_ft_read()
{
	char	*file = "./main.c"; 
	int		fd1 = open(file, O_RDONLY);
	int		fd2 = open(file, O_RDONLY);

	if (fd1 == -1 || fd2 == -1) {
		printf("Error opening file %s \n", file);
		if (fd1 != -1)
			close(fd1);
		if (fd2 != -1)
			close(fd2);
		return ;
	}

	char	buffer[78];
	char	bufferFt[78];

	int		bytesReadFt = ft_read(fd1, bufferFt, sizeof(bufferFt) - 1);
	int		bytesRead = read(fd2, buffer, sizeof(buffer) - 1);

	printf("%i bytes red from ft_read %s\n", bytesReadFt, file);
	printf("%i bytes red from read %s\n", bytesRead, file);

	if (bytesRead > 0) {
		printf("File contents ft_read:\n%s\n", bufferFt);
	} else {
		printf("File contents read:\n%s\n", strerror(errno));
	}

	if (bytesReadFt > 0) {
		printf("File contents read:\n%s\n", buffer);
	}

	close(fd1);
	close(fd2);
}


void test_ft_strdup()
{
	char str_to_duplicate[50] = "That is a good string to duplicate in my opinion\n";
	char *null_str = NULL;

	char *ft_duplicate = ft_strdup(str_to_duplicate);
	char *duplicate = strdup(str_to_duplicate);

	printf("Original function: %s", duplicate);
	printf("Custom function: %s", ft_duplicate);


	printf("Testing empty string:\n");
	char *ft_dup_null = ft_strdup(null_str);
	// char *dup_null = strdup(null_str);

	// printf("Null string printing: %s", dup_null);
	printf("Null string printing ft: %s", ft_dup_null);

	if (ft_duplicate)
		free(ft_duplicate);
	if (duplicate)
		free(duplicate);
	if (ft_dup_null)
		free(ft_dup_null);
	// if (dup_null)
	// 	free(dup_null);
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

		printf("=========READ===========\n");
		test_ft_read();

		printf("=========STRDUP===========\n");
		test_ft_strdup();

	}
	return 0;
}
