/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:43:09 by dierojas          #+#    #+#             */
/*   Updated: 2025/02/03 21:03:40 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destn;
	const unsigned char	*sourc;

	if (!dst || !src)
		return (NULL);
	destn = (unsigned char *)dst;
	sourc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destn[i] = sourc[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int	main ()
{
	char src [] = "Hola Mundo";
	char dest [10] = "ADIOS";	
	size_t len = 4;
	unsigned char c = 'A';

	printf("%s\n", src);
	printf("%s\n", dest);

	ft_memcpy(dest, src, len);
	dest[len] = '\0';

	printf("%s\n", src);
	printf("%s\n", dest);
	return 0;
}
*/
