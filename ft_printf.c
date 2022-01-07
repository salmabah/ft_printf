/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahraou <sbahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:28:53 by sbahraou          #+#    #+#             */
/*   Updated: 2022/01/07 14:11:34 by sbahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"

void	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char		c;
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		c = '-';
		write(1, &c, 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

int print_digit(va_list paramsinfos)
{
	int n;
	int nb_chiffres;

	n = (int)va_arg(paramsinfos, int);
	ft_putnbr(n);
	nb_chiffres = 0;
	while (n > 0)
	{
		nb_chiffres++;
		n /= 10;
	}
	return (nb_chiffres);
}

int	print_str(va_list paramsinfos)
{
	int	n;
	char *s;

	n = 0;
	ft_strdub(s, va_arg(paramsinfos, const char *));
	ft_putstr(s);
	n = ft_strlen(s);
	return (n);
}

int	print_format(char f, va_list paramsinfos)
{
	int	cnt;

	cnt = 0;
	if (f == 'd')
		cnt += print_digit(paramsinfos);
	else if (f == 's')
		cnt += print_str(paramsinfos);
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	int i;
	int nb_print;
	va_list paramsinfos;

	va_start(paramsinfos, s);
	i = 0;
	nb_print = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			nb_print++;
		}
		else
		{
			i++;
			nb_print += print_format(s[i], paramsinfos);
		}
		printf("%s", va_arg(paramsinfos, const char *));
		i++;
	}
	va_end(paramsinfos);
	return (0);
}

int main(int argc, char *argv[])
{
	ft_printf("Hello %s %d", argv[1], argv[2], argv[3]);
}