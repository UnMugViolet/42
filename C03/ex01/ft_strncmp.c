/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:26:56 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/04 16:53:41 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		if (s1[i] != s2[i] || i < n - 1)
		{
			return ((unsigned int)s1[i] - (unsigned int)s2[i]);
		}
		i++;
	}
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "wertyuiopqaz";
	char s2[] = "wertyuiopq";

	int result1 = strncmp(s1, s2, 0);
	int result2 = ft_strncmp(s1, s2, 0);

	printf("strncmp %i\n", result1);
	printf("custom %i", result2);
}
