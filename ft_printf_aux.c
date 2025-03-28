/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:25:56 by dierojas          #+#    #+#             */
/*   Updated: 2025/03/28 09:31:08 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexdec_aux(char const *s, va_list args)
{
	size_t				i;
	unsigned long long	lnb;
	int					count;

	i = 0;
	count = 0;
	if (s[i] == 'x')
	{
		lnb = va_arg(args, unsigned int);
		count += ft_put_hexdec(lnb, 0);
	}
	else if (s[i] == 'X')
	{
		lnb = va_arg(args, unsigned int);
		count += ft_put_hexdec(lnb, 1);
	}
	return (count);
}

int	ft_pointer_aux(va_list args)
{
	unsigned long long	lnb;
	int					count;

	count = 0;
	lnb = va_arg(args, unsigned long long);
	if (!lnb)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_put_hexdec(lnb, 0);
	}
	return (count);
}

int	ft_putchar_aux(va_list args)
{
	char	c;
	int		count;

	count = 0;
	c = va_arg(args, int);
	count += ft_putchar(c);
	return (count);
}

int	ft_putnbr_aux(char const *s, va_list args)
{
	size_t				i;
	int					count;
	int					n;
	unsigned int		np;

	i = 0;
	count = 0;
	n = 0;
	np = 0;
	if (s[i] == 'd' || s[i] == 'i')
	{
		n = va_arg(args, int);
		count += ft_putnbr(n);
	}
	else if (s[i] == 'u')
	{
		np = va_arg(args, unsigned int);
		count += ft_put_unsnbr(np);
	}
	return (count);
}

int	ft_putstr_aux(va_list args)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(args, char *);
	count += ft_putstr(str);
	return (count);
}
