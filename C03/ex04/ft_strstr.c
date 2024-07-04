/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:09:13 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/04 14:45:12 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			temp = i;
			while (str[temp] != 0 && str[temp] == to_find[j])
			{
				temp++;
				j++;
				if (j == ft_strlen(to_find))
				{
					return (&str[i]);
				}
			}
		}
		i++;
	}
	return (0);
}

/* #include <unistd.h>

int	main(void)
{
	char	needle[] = "Terr";
	char	haystack[] = "Pomme De Terre";
	char	*result;

	result = ft_strstr(haystack, needle);

	write(1, result, ft_strlen(result));
	write(1, result, 1);
} */