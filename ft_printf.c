/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:53:22 by dierojas          #+#    #+#             */
/*   Updated: 2025/03/28 09:30:15 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	va_list	args;
	size_t	i;
	int		char_count;

	va_start(args, s);
	i = 0;
	char_count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			char_count += ft_aux_01(&s[i], args);
		}
		else
			char_count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (char_count);
}

int	ft_aux_01(const char *s, va_list args)
{
	int		char_count;
	size_t	i;

	i = 0;
	char_count = 0;
	if (s[i] == 'c')
		char_count += ft_putchar_aux(args);
	else if (s[i] == '%')
		char_count += ft_putchar('%');
	else if (s[i] == 's')
		char_count = ft_putstr_aux(args);
	else if (s[i] == 'd' || s[i] == 'i' || s[i] == 'u')
		char_count += ft_putnbr_aux(s, args);
	else if (s[i] == 'p')
		char_count += ft_pointer_aux(args);
	else if (s[i] == 'x' || s[i] == 'X')
		char_count += ft_hexdec_aux(s, args);
	else
		char_count += ft_putstr("(null)");
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
