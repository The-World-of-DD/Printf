/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:39:44 by dierojas          #+#    #+#             */
/*   Updated: 2025/03/08 12:09:02 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = malloc (len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/* 
#include <stdio.h>

int main ()
{
    printf ("%s\n", ft_substr("Hola Mundo", 7, 10));
    printf ("%s\n", ft_substr("Hola Mundo", 3, 5));
    printf ("%s\n", ft_substr("Hola Mundo", 10, 10));
	printf ("%s\n", ft_substr("", 0, 1));
	printf ("%s\n", ft_substr("", 1, 1));
	printf ("%s\n", ft_substr("hola", 0, 4));
	
	return 0;
}
 */
