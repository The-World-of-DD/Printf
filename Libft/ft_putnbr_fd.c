/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:47:01 by dierojas          #+#    #+#             */
/*   Updated: 2025/02/02 03:24:24 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int main()
{
	ft_putnbr_fd(12345, 1);
	ft_putchar_fd(1, '\n');
	// ft_putnbr_fd(-6789, 1);
	// ft_putchar_fd(1, '\n');
	// ft_putnbr_fd(0, 1);
	// ft_putchar_fd(1, '\n');
	// ft_putnbr_fd(-2147483648, 1);
	// ft_putchar_fd(1, '\n');

	return 0;
}
*/
