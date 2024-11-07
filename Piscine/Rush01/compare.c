/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:26:36 by agouin            #+#    #+#             */
/*   Updated: 2024/07/07 19:39:29 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_verif_col(int **tab_init, int **tab_param);
int		is_verif_row(int **tab_init, int **tab_param);
void	ft_print_dbl_tab(int **tab);

int	is_valid(int **tab_init, int nb, int row, int col)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (tab_init[row][k] == nb || tab_init[k][col] == nb)
			return (0);
		k++;
	}
	return (1);
}

int	is_verif(int **tab_init, int **tab_param)
{
	if (is_verif_row(tab_init, tab_param) && is_verif_col(tab_init, tab_param))
		return (1);
	return (0);
}
