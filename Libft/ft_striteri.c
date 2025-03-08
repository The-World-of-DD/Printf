/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas <dierojas@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:44:02 by dierojas          #+#    #+#             */
/*   Updated: 2025/01/24 22:59:50 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// #include <stdio.h>
// void to_uppercase(unsigned int i, char *c) {
//     // Si el carácter es minúscula, lo convertimos a mayúscula
//     if (*c >= 'a' && *c <= 'z') {
//         *c -= 32; // Convertir a mayúscula
//     }
// }

// int main() {
//     char str[] = "hola, mundo";
//     ft_striteri(str, to_uppercase);
//     printf("%s\n", str); // Salida: "HOLA, MUNDO"
//     return 0;
// }