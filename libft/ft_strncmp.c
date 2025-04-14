/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:26:15 by dd                #+#    #+#             */
/*   Updated: 2025/02/03 21:10:41 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/* // No se si el compare se le puede aplicar el !src por la comparacion
#include <stdio.h>
#include <string.h>
int main () 
{
    printf("%d\n", ft_strncmp("Abls", "l", 4));
    printf("%d\n", ft_strncmp("Abls", "s", 3));
    printf("%d\n", ft_strncmp("Abls", "O", 3));
    printf("%d\n", strncmp("Abhhhls", "l", 4));
    printf("%d\n", strncmp("Abljbjbjs", "s", 3));
    printf("%d\n", strncmp("Abls", "O", 3));
	printf("%d\n", strncmp("Abls", "\0", 3));
	printf("%d\n", strncmp("\0", "sss", 0));
	
	return 0;
} 
 */
