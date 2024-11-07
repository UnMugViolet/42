/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:52:30 by mprokosc          #+#    #+#             */
/*   Updated: 2024/07/07 19:40:01 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid(int **tab_init, int nb, int i, int j);
int		is_verif(int **tab_init, int **tab_param);
void	ft_print_dbl_tab(int **tab);

int	verif_sky_left(int *line)
{
	int	i;
	int	count;
	int	max;

	count = 0;
	i = count;
	max = count;
	while (i < 4)
	{
		if (line[i] > max)
		{
			count++;
			max = line[i];
		}
		i++;
	}
	return (count);
}

int	verif_sky_right(int *line)
{
	int	i;
	int	count;
	int	max;

	count = 0;
	max = count;
	i = 3;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			count++;
			max = line[i];
		}
		i--;
	}
	return (count);
}

int	is_verif_row(int **tab_init, int **tab_param)
{
	int	row;
	int	col;
	int	line[4];

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			line[row] = tab_init[row][col];
			row++;
		}
		if (verif_sky_left(line) != tab_param[2][col])
			return (0);
		if (verif_sky_right(line) != tab_param[3][col])
			return (0);
		col++;
	}
	return (1);
}

int	is_verif_col(int **tab_init, int **tab_param)
{
	int	row;
	int	col;
	int	line[4];

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			line[row] = tab_init[col][row];
			row++;
		}
		if (verif_sky_left(line) != tab_param[2][col])
			return (0);
		if (verif_sky_right(line) != tab_param[3][col])
			return (0);
		col++;
	}
	return (1);
}

int	ft_backtracking(int **tab_init, int **tab_param, int row, int col)
{
	int	val;
	int	new_col;
	int	new_row;

	if (row == 4)
		return (is_verif(tab_init, tab_param));
	new_row = row + ((col + 1) / 4);
	new_col = (col + 1) % 4;
	if (tab_init[row][col] != 0)
		return (ft_backtracking(tab_init, tab_param, new_row, new_col));
	val = 1;
	while (val <= 4)
	{
		if (is_valid(tab_init, val, row, col))
		{
			tab_init[row][col] = val;
			if (ft_backtracking(tab_init, tab_param, new_row, new_col))
				return (1);
			tab_init[row][col] = 0;
		}
		val++;
	}
	return (0);
}
