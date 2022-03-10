/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahraou <sbahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:46:04 by sbahraou          #+#    #+#             */
/*   Updated: 2022/02/25 01:10:10 by sbahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<unistd.h>
# include	<stdarg.h>
# include	<stdlib.h>
# include	<limits.h>

int	print_hexa_x(int nb, char f, int *cnt);
int	print_unsigned(unsigned int n, int *cnt);
int	print_hex(long nb, int *cnt);
int	print_adress(va_list paramsinfos, int *cnt);
int	ft_putstr(const char *s);
int	ft_putnbr(int n, int *cnt);
int	ft_putchar(int c);
int	print_format(char f, va_list paramsinfos);
int	ft_printf(const char *s, ...);
#endif