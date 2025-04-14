/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:05:25 by dd                #+#    #+#             */
/*   Updated: 2025/02/03 05:42:52 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char )ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
void *result = ft_memchr("Hola Mundo", 111, 10);
if (result != NULL)
    printf("%s\n", (char *)result);
else
    printf("NULL\n");

void *result1 = memchr("Hola Mundo", 111, 10);
if (result1 != NULL)
    printf("%s\n", (char *)result1);
else
    printf("NULL\n");
}
*/
