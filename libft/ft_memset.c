/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:58:01 by dierojas          #+#    #+#             */
/*   Updated: 2025/01/16 08:25:54 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ch;
	unsigned int	i;

	ch = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ch[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>

int	main ()
{
	char src [] = "Hola Mundo";
	size_t len = 4;
	unsigned char c = 'A';

	printf("%p\n", ft_memset(src, c, len));
	printf("%s\n", src);
}
*/
