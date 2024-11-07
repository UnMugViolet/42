/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:17:11 by agouin            #+#    #+#             */
/*   Updated: 2024/07/07 19:40:17 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_input(int argc, char **argv);
void	ft_print(unsigned int output, char *str, unsigned int newline);
void	ft_print_dbl_tab(int **tab);
void	all_conditions(int **param, int **tab_init);
int		ft_backtracking(int **tab_init, int **tab_param, int row, int col);
void	ft_print_dbl_tab(int **tab);

void	ft_cpy_array(int col, int k, char **av, int array[4])
{
	int	i;
	int	j;

	i = col;
	j = 0;
	while ((av[1][i]) && (i < k))
	{
		if (av[1][i] != ' ')
		{
			array[j] = (av[1][i] - '0');
			j++;
		}
		i++;
	}
}

void	allocate_memory(int ***array)
{
	int	i;

	i = 0;
	*array = (int **)malloc(4 * sizeof(int *));
	while (i < 4)
	{
		(*array)[i] = (int *)malloc(4 * sizeof(int));
		i++;
	}
}

void	free_memory(int **array)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	launch_the_thing(int **array, int **tab_init, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		ft_cpy_array(j, (j + 8), av, array[i]);
		i++;
		j += 8;
	}
	all_conditions(array, tab_init);
	if (ft_backtracking(tab_init, array, 0, 0))
		ft_print_dbl_tab(tab_init);
	else
	{
		ft_print(2, "Error", 1);
	}
}

int	main(int ac, char **av)
{
	int	**array;
	int	**tab_init;

	array = NULL;
	if (ft_check_input(ac, av))
		return (0);
	allocate_memory(&array);
	allocate_memory(&tab_init);
	launch_the_thing(array, tab_init, av);
	free_memory(array);
	free_memory(tab_init);
	return (0);
}
