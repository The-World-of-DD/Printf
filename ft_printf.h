/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:51:27 by dierojas          #+#    #+#             */
/*   Updated: 2025/03/28 09:16:32 by dierojas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_put_unsnbr(unsigned int n);
int	ft_put_hexdec(unsigned long long nb, int m);
int	ft_hexdec_aux(char const *s, va_list args);
int	ft_pointer_aux(va_list args);
int	ft_putchar_aux(va_list args);
int	ft_putnbr_aux(char const *s, va_list args);
int	ft_putstr_aux(va_list args);
int	ft_aux_01(const char *s, va_list args);
int	ft_printf(char const *s, ...);

#endif
