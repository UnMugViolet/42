#include <stdio.h>
#include <libasm.h>
#include <string.h>
#include <errno.h>

int main(int ac, char **av)
{
	if (ac != 2) {
		printf("Not enough arguments\n");
	} else {
		printf("Text: %s\nLen: %zu\n", av[1] ,ft_strlen(av[1]));
		printf("Text: %s\nLen: %zu\n", av[1] , strlen(av[1]));

		char dst[6] = "youpi";
		char const cpy[4] = "pip";

		
		printf("OG: %s", dst);
		printf(" modified: %s\n", ft_strcpy(dst, cpy));
	}
	return 0;
}
