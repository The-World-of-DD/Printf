/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:27:28 by dierojas          #+#    #+#             */
/*   Updated: 2025/02/03 05:28:11 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
//la funcion no se si puede ser nula
// {
// static char	ft_prueba(unsigned int n, char c)
// 	if (n % 2 == 1)
// 		return (c - 32);
// 	return c;
// }
// #include <stdio.h>
// int	main()
// {
// 	const char *str = "Hola mundo!";
// 	char *result;
// 	result = ft_strmapi(str, ft_prueba);	
// 	printf("Old one: %s\n", str);
// 	printf("New one: %s\n", result);
// 	free(result);
// 	return 0;
// }
