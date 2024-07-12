/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:44:53 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/06 18:39:41 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print(unsigned int output, char *str, unsigned int newline);
int		ft_strlen(char *str);

int	is_allowed_digit(char c)
{
	if (c >= '1' && c <= '4')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	check_error(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (i % 2)
		{
			if (!is_space(argv[1][i]))
			{
				ft_print(2, "Error", 1);
				return (1);
			}
			i++;
		}
		else
		{
			if (!is_allowed_digit(argv[1][i]))
			{
				ft_print(2, "Error", 1);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	ft_check_input(int argc, char **argv)
{
	int	str_lenght;

	str_lenght = ft_strlen(argv[1]);
	if (str_lenght != 31 || argc != 2)
	{
		ft_print(2, "Error", 1);
		return (1);
	}
	if (check_error(argv))
		return (1);
	return (0);
}
