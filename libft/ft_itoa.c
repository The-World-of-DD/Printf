/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:30 by dierojas          #+#    #+#             */
/*   Updated: 2025/02/02 03:32:56 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_mem(long nb);
static char	*ft_mem_al(int ito_len);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*ito;
	long	nb;

	nb = (long)n;
	len = ft_count_mem(nb);
	ito = ft_mem_al(len);
	if (!ito)
		return (NULL);
	ito[len] = '\0';
	if (nb < 0)
		nb = -nb;
	i = len - 1;
	while (nb > 0)
	{
		ito[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	if (n < 0)
		ito[0] = '-';
	if (n == 0)
		ito[0] = '0';
	return (ito);
}

static char	*ft_mem_al(int ito_len)
{
	char	*len;

	len = malloc((ito_len + 1) * sizeof(char));
	if (!len)
		return (NULL);
	return (len);
}

static	int	ft_count_mem(long nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	if (nb == 0)
		count++;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
/*
#include "stdio.h"

int	main ()
{
	int a = 21111112;
	int b = -21111112;
	int c = 0;
	
	printf("%s\n", ft_itoa(a));
	printf("%s\n", ft_itoa(b));
	printf("%s\n", ft_itoa(c));
	
	return 0;
}
*/
