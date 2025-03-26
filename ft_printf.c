/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:53:22 by dierojas          #+#    #+#             */
/*   Updated: 2025/03/26 21:56:33 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(char const *s, ...)
{
	size_t	i;
	va_list	args;

	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')//aqui identificamos el % antes del identificador
		{
			i++;
			if (s[i] == 'c')//caracter
			{
				char c = va_arg(args, int);
				ft_putchar_fd(c, 1);
			}
			else if (s[i] == '%')//caracter
				ft_putchar_fd('%', 1);
			else if (s[i] == 's')//esto es un string
			{
				char *str = va_arg(args, char*);
				ft_putstr_fd(str, 1);
			}
			else if (s[i] == 'i')//esto es un int
			{
				int n = va_arg(args, int);
				ft_putnbr_fd(n, 1);
			}
			else
				ft_putstr_fd("(nill)", 1);
		}
		else 
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>
int	main()
{
    printf("PROBANDO CARÁCTER -> %c\n", 'c');
	printf("PROBANDO STRING -> %s\n", "sherlocked");
	printf("PROBANDO PORCENTAJE %%\n");
	printf("PROBANDO ENTERO -> %i\n  %i\n", 5678, -5678);

	ft_printf("Hola Mundo\n -- %c -- %% -- %s -- %i\n", 'c', "Mis muertos", 234564);

	/*
	printf("PROBANDO VOID -> %p\n", (void *)"holo");
	printf("PROBANDO DECIMAL -> %d\n", 123345);
    printf("PROBANDO NUMERO DECIMAL UNSIGNED %u\n", -2345);
    printf("PROBANDO HEX MIN %x\n", 2345);
    printf("PROBANDO HEX MAY %X\n", 2345);
    */

    return 0;
}
