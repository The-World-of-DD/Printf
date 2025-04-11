/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:29:38 by dierojas          #+#    #+#             */
/*   Updated: 2025/01/26 21:47:29 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	len;
	size_t	start;
	size_t	end;

	if (!set || !s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	s2 = malloc((len + 1) * (sizeof (char)));
	if (!s2)
		return (NULL);
	end = 0;
	while (end < len)
	{
		s2[end] = s1[start + end];
		end++;
	}
	s2[len] = '\0';
	return (s2);
}
/*
#include <stdio.h>

int	main ()
{
	char	*res=ft_strtrim("***HolaMundo***", "*");
	char	*res2=ft_strtrim("HolaMundo", "Ho");
	printf("%s\n", res);
	printf("%s\n", res2);
	free(res);
	free(res2);

	return 0;	
}
*/