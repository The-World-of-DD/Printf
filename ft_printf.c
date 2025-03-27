/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:53:22 by dierojas          #+#    #+#             */
/*   Updated: 2025/03/27 11:35:23 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	size_t			i;
	va_list			args;
	int				n;
	char			*str;
	char			c;
	unsigned int	np;
	unsigned long long	lnb;

	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')//aqui identificamos el % antes del identificador
		{
			i++;
			if (s[i] == 'c')//caracter
			{
				c = va_arg(args, int);
				ft_putchar_fd(c, 1);
			}
			else if (s[i] == '%')//caracter %
				ft_putchar_fd('%', 1);
			else if (s[i] == 's')//esto es un string
			{
				str = va_arg(args, char*);
				ft_putstr_fd(str, 1);
			}
			else if (s[i] == 'd' || s[i] == 'i')//esto es un numero en base decimal
			{
				n = va_arg(args, int);
				ft_putnbr_fd(n, 1);
			}
			else if (s[i] == 'u')
			{
				np = va_arg(args, unsigned int);
				ft_put_unsnbr_fd(np, 1);
			}
			else if (s[i] == 'x' || s[i] == 'X' || s[i] == 'p')
			{
				lnb = va_arg(args, unsigned long long);
				ft_put_hexdec(lnb, 1);
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

int main() 
{
    int numero = -255;
    unsigned int numero_unsigned = 255;
    char letra = 'A';
    char saludo[] = "Hola Mundo";
    void *direccion = &numero;

    printf("Número con signo: %d -- OK\n", numero);  // -255
    printf("Número unsigned: %u -- OK\n", numero_unsigned);  // 255
    printf("Carácter: %c -- OK\n", letra);  // A
    printf("Cadena: %s -- OK\n", saludo);  // Hola Mundo
    printf("Dirección de memoria: %p\n", direccion);  // Dirección de memoria
    printf("Hexadecimal minúsculas: %x\n", numero_unsigned);  // ff
    printf("Hexadecimal mayúsculas: %X\n", numero_unsigned);  // FF
    printf("Porcentaje: %% -- OK\n");  // %

	ft_printf("Hola Mundo\n%c -- %% -- %s -- %d\n --", 'c', "Mis muertos", 234564);

    return 0;
} 
