/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:08:22 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/11 16:47:34 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned int)s1[i] - (unsigned int)s2[i]);
	}
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

int	main(int argc, char **argv)
{
	int i;
	(void)argc;

	i = 0;
	while (argv[i])
	{
		write(1, &argv[i], ft_strlen(argv[i]));
		i++;
	}
}