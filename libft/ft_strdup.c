/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 23:41:22 by dierojas          #+#    #+#             */
/*   Updated: 2025/02/03 05:21:48 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src);

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1) + 1;
	str = malloc(i);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>

int main ()
{
    char arr[] = "Hola Mundollr";
    printf("%s\n", arr);
    printf("%s\n", ft_strdup(arr));
    free (arr);
    return 0;
}
*/
