/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:44:23 by agouin            #+#    #+#             */
/*   Updated: 2024/07/07 16:37:24 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	row14(int **param, int **tab_init, int n);
void	col14(int **param, int **tab_init, int n);
void	row12(int **param, int **tab_init, int n);
void	col12(int **param, int **tab_init, int n);

void	row13(int **param, int **tab_init, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if ((param[0][i] == 3) && (param[1][i] == 1))
			tab_init[i][3] = 4;
		if ((param[0][i] == 1) && (param[1][i] == 3))
			tab_init[i][0] = 4;
		i++;
	}
}

void	col13(int **param, int **tab_init, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if ((param[2][i] == 3) && (param[3][i] == 1))
			tab_init[3][i] = 4;
		if ((param[2][i] == 1) && (param[3][i] == 3))
			tab_init[0][i] = 4;
		i++;
	}
}

void	all_conditions(int **param, int **tab_init)
{
	row14(param, tab_init, 4);
	col14(param, tab_init, 4);
	row12(param, tab_init, 4);
	col12(param, tab_init, 4);
	row13(param, tab_init, 4);
	col13(param, tab_init, 4);
}
