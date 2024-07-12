/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:44:17 by pjaguin           #+#    #+#             */
/*   Updated: 2024/07/03 13:07:44 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != 0 && i != n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char src[] = "blah bleh";
	char dest[9];
	unsigned int n = 4;

	ft_strncpy(dest, src, n);

	printf("%s", dest);
} */