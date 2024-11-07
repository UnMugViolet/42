/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:26:31 by agouin            #+#    #+#             */
/*   Updated: 2024/07/07 15:38:23 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	row14(int **param, int **tab_init, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if ((param[0][i] == 4) && (param[1][i] == 1))
		{	
			tab_init[i][0] = 1;
			tab_init[i][1] = 2;
			tab_init[i][2] = 3;
			tab_init[i][3] = 4;
		}
		if ((param[0][i] == 1) && (param[1][i] == 4))
		{
			tab_init[i][0] = 4;
			tab_init[i][1] = 3;
			tab_init[i][2] = 2;
			tab_init[i][3] = 1;
		}
		i++;
	}
}

void	col14(int **param, int **tab_init, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if ((param[2][i] == 4) && (param[3][i] == 1))
		{	
			tab_init[0][i] = 1;
			tab_init[1][i] = 2;
			tab_init[2][i] = 3;
			tab_init[3][i] = 4;
		}
		if ((param[2][i] == 1) && (param[3][i] == 4))
		{
			tab_init[0][i] = 4;
			tab_init[1][i] = 3;
			tab_init[2][i] = 2;
			tab_init[3][i] = 1;
		}
		i++;
	}
}

void	row12(int **param, int **tab_init, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if ((param[0][i] == 2) && (param[1][i] == 1))
		{	
			tab_init[i][0] = 3;
			tab_init[i][3] = 4;
		}
		if ((param[0][i] == 1) && (param[1][i] == 2))
		{
			tab_init[i][0] = 4;
			tab_init[i][3] = 3;
		}
		i++;
	}
}

void	col12(int **param, int **tab_init, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if ((param[2][i] == 2) && (param[3][i] == 1))
		{	
			tab_init[0][i] = 3;
			tab_init[3][i] = 4;
		}
		if ((param[2][i] == 1) && (param[3][i] == 2))
		{
			tab_init[0][i] = 4;
			tab_init[3][i] = 3;
		}
		i++;
	}
}
