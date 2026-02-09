#include <stdio.h>
#include <libasm.h>

int main(int ac, char **av)
{
	if (ac == 2) {
		printf("Text: %s\nLen: %zu\n", av[1] ,ft_strlen(av[1]));
	}
	return 0;
}
