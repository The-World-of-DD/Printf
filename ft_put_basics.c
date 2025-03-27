/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_basics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:37:10 by dierojas          #+#    #+#             */
/*   Updated: 2025/03/27 11:01:52 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
		ft_putnbr_fd ((n / 10), fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		s++;
	}
}

void	ft_put_unsnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_fd ((n / 10), fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
/* void	ft_put_hexdec(unsigned long long nb, int fd)
{
	char	minh;
	char	maxh;
	int		result;

	minh = "0123456789abcdef"[nb/10];//aqui indicamos la posicion dentro del caracter
	maxh = "0123456789ABCDEF"[nb%10];
	if ()
	return (result);
}
 */
