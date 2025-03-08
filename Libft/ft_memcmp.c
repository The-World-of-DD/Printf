/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:36:39 by dierojas          #+#    #+#             */
/*   Updated: 2025/02/03 21:11:04 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 || !s2)
		return (-1);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
    int s = memcmp("Hola Mundo", "Hola Mundo", 10);
    int s1 = ft_memcmp("Hola Mundo", "Hola Mundo", 10);
    if (s == 0)
        printf("Thats equal: %i\n", s);
    else
        printf("Thats not equal: %i\n", s);
    if (s1 == 0)
        printf("Thats equal: %i\n", s1);
    else
        printf("Thats not equal: %i\n", s1);
}
*/
