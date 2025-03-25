/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:53:22 by dierojas          #+#    #+#             */
/*   Updated: 2025/03/24 15:39:34 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//int	ft_printf(char const *, ...)
int	ft_printf(char const *s)
{
	size_t	i;
	//char	*s;//una cosa es lo que ttiene el % y la otra es el sting que le pasamos¿?
	char	*printed;//esto es necesario¿?¿?¿

	while (s)
	{
		if (s[i] == '%')//aqui identificamos el % antes del identificador
		{
			i++;//avanza 1 y siempre lo tiene que hacer
			if (s[i] == 'c')
				ft_putchar_fd(s[i], 1);
			if (s[i] == '%')
				ft_putchar_fd('%', 1);
			else if (s[i] == 's')
				ft_putstr_fd(s, 1);
			else if (s[i] == 'p')
				ft_putstr_fd(s, 1);
			else if (s[i] == 'i')
				ft_putnbr_fd(s[i], 1);
			else
				ft_putstr_fd("nill", 1);
		}
		ft_putstr_fd(s[i], 1);
		i++;
	}
	return (0);
}

#include <stdio.h>
int	main()
{
    printf("PROBANDO CARÁCTER -> %c\n", 'c');	
	printf("PROBANDO STRING -> %s\n", "sherlocked");
	printf("PROBANDO PORCENTAJE %%\n");
	printf("PROBANDO ENTERO -> %i\n  %i\n", 5678, -5678);

	//ft_printf("Hola Mundo");

	/*
	printf("PROBANDO VOID -> %p\n", (void *)"holo");
	printf("PROBANDO DECIMAL -> %d\n", 123345);
    printf("PROBANDO NUMERO DECIMAL UNSIGNED %u\n", -2345);
    printf("PROBANDO HEX MIN %x\n", 2345);
    printf("PROBANDO HEX MAY %X\n", 2345);
    */

    return 0;
}
