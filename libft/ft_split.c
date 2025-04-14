/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:11:23 by dierojas          #+#    #+#             */
/*   Updated: 2025/02/03 05:33:24 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c);
static char	*ft_strcpy(char *dst, const char *src, size_t len);
static void	ft_test_mem_free(char **str, int j);
static char	**ft_split_process(const char *s, char c, char **str, int i);

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc((ft_word_count(s, c) + 1) * (sizeof(char *)));
	if (!str)
		return (NULL);
	str = ft_split_process(s, c, str, i);
	return (str);
}

static int	ft_word_count(const char *s, char c)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word_count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word_count);
}

static char	*ft_strcpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	ft_test_mem_free(char **str, int j)
{
	if (!str[j])
	{
		while (j > 0)
			free (str[--j]);
		free(str);
	}
}

static char	**ft_split_process(const char *s, char c, char **str, int i)
{
	int	start;
	int	j;

	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			str[j] = malloc((i - start + 1) * sizeof(char));
			if (!str[j])
			{
				ft_test_mem_free(str, j);
				return (NULL);
			}
			ft_strcpy(str[j], &s[start], i - start);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

/* 
static void	ft_main_free_mem(char **words)
{
	int	i;

	if (!words)
		return ;
	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}

#include <stdio.h>
int	main(void)
{
	char	*str = "Hola,,,Hola,Mundo,Adios,Mundo,,,,,,Adios";
	char	*str2 = ",Hola,,Adios,";
	char	c = ',';

	char **words = ft_split(str, c);
	if (words)
	{
		int i = 0;
		while (words[i])
		{
			printf("Word %d: %s\n", i, words[i]);
			i++;
		}
		ft_main_free_mem(words); // Free the main array
	}
	return 0;
}
 */
