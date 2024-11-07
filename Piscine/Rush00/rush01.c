/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:14:20 by fzaazaa           #+#    #+#             */
/*   Updated: 2024/06/30 13:59:30 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_putchar.c"
// prints the extrem, 0 for top, 1 for bottom
void	print_ex(int cols, char first_char, char last_char)
{
	int	count;

	count = 0;
	if (cols == 0)
	{
		return ;
	}
	ft_putchar(first_char);
	if (cols < 2)
	{
		ft_putchar('\n');
		return ;
	}
	if (cols > 1)
	{
		while (count < cols - 2)
		{
			ft_putchar('*');
			count++;
		}
	}
	ft_putchar(last_char);
	ft_putchar('\n');
}

// prints the middle parts of the drawing
void	print_mid(int cols, int rows)
{
	int	y_axis;
	int	x_axis;

	if (cols == 0)
		return ;
	if (rows == 0)
		return ;
	y_axis = 0;
	while (y_axis < rows - 2)
	{
		x_axis = 0;
		while (x_axis < cols)
		{
			if (x_axis == 0)
				ft_putchar('*');
			else if (x_axis == cols - 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
			x_axis++;
		}
		ft_putchar('\n');
		y_axis++;
	}
}

// prints the string on the stdout (console outpout)
void	ft_put_str(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	write(1, str, c);
}

// returns 1 if the cols and rows are valid, otherwise, 0
int	check_value(int cols, int rows)
{
	if (cols < 0 && rows < 0)
	{
		ft_put_str("rows & cols must be at least  0\n");
		return (1);
	}
	if (cols < 0)
	{
		ft_put_str("columns must be at least 0\n");
		return (1);
	}
	if (rows < 0)
	{
		ft_put_str("rows must be at least  0\n");
		return (1);
	}
	return (0);
}

// Called at the end in order to know the functions before using them
void	rush(int x, int y)
{
	if (check_value(x, y) == 1)
	{
		return ;
	}
	print_ex(x, '/', '\\');
	print_mid(x, y);
	print_ex(x, '\\', '/');
}
