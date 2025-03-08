/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:36:51 by dierojas          #+#    #+#             */
/*   Updated: 2025/02/18 16:52:11 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (-1);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main()
{
	char src [] = "ADIOS";
	char dest [10] = "Hola Mundo";
	size_t len = 4;

	printf("%s\n", src);
	printf("%s\n", dest);

	printf ("%zu\n", ft_strlcpy(dest, src, len));

	printf("%s\n", src);
	printf("%s\n", dest);
}
*/
