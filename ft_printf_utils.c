/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:37:10 by dierojas          #+#    #+#             */
/*   Updated: 2025/03/28 09:31:48 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		count++;
	}
	if (n >= 10)
		count += ft_putnbr((n / 10));
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	count = 0;
	while (s[count])
	{
		ft_putchar(s[count]);
		count++;
	}
	return (count);
}

int	ft_put_unsnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_put_unsnbr((n / 10));
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_put_hexdec(unsigned long long nb, int m)
{
	char	minh;
	char	maxh;
	int		count;

	minh = "0123456789abcdef"[nb % 16];
	maxh = "0123456789ABCDEF" [nb % 16];
	count = 0;
	if (nb >= 16)
		count += ft_put_hexdec(nb / 16, m);
	if (!m)
		count += ft_putchar(minh);
	else
		count += ft_putchar(maxh);
	return (count);
}
