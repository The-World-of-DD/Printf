/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dd <dd@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 02:15:59 by dd                #+#    #+#             */
/*   Updated: 2025/01/18 02:42:20 by dd               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/* 
#include <string.h>
#include <stdio.h>

int main ()
{
    char ss[] = "Hola Mundollllll";
    int s = 111;
    int s1 = 115;

    printf("%s\n", ft_strrchr(ss, s));
    printf("%s\n", strrchr(ss, s));

    return 0;
}
 */
