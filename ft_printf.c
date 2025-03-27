/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:53:22 by dierojas          #+#    #+#             */
/*   Updated: 2025/03/27 15:23:52 by dierojas         ###   ########.fr       */
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
	int	char_count;

	va_start(args, s);
	i = 0;
	char_count = 0;
	while (s[i])
	{
		if (s[i] == '%')//aqui identificamos el % antes del identificador
		{
			i++;
			if (s[i] == 'c')//caracter
			{
				c = va_arg(args, int);
				char_count += ft_putchar(c);
			}
			else if (s[i] == '%')//caracter %
				char_count += ft_putchar('%');
			else if (s[i] == 's')//esto es un string
			{
				str = va_arg(args, char *);
				char_count += ft_putstr(str);
			}
			else if (s[i] == 'd' || s[i] == 'i')//esto es un numero en base decimal
			{
				n = va_arg(args, int);
				char_count += ft_putnbr(n);
			}
			else if (s[i] == 'u')
			{
				np = va_arg(args, unsigned int);
				char_count += ft_put_unsnbr(np);
			}
			else if (s[i] == 'x')
			{
				lnb = va_arg(args, unsigned int);
				char_count += ft_put_hexdec(np, 0);//tengo que modificar este valor
			}
			else if (s[i] == 'X')
			{
				lnb = va_arg(args, unsigned int);
				char_count += ft_put_hexdec(np, 1);//tengo que modificar este valor
			}
			else if (s[i] == 'p')
			{
				lnb = va_arg(args, unsigned long long);
				char_count += ft_putstr("0x");
				char_count += ft_put_hexdec(lnb, 0);//tengo que modificar este valor
			}
			else
				char_count += ft_putstr("(nill)");
		}
		else 
			char_count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (char_count);
}
/*  
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

	ft_printf("Hola Mundo\n%c -- %% -- %s -- %d --", 'c', "Mis muertos", 234564);

    return 0;
}
 */
