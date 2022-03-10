/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahraou <sbahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:28:53 by sbahraou          #+#    #+#             */
/*   Updated: 2022/02/26 14:48:43 by sbahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	i;
	int	nb_chiffres;

	nb_chiffres = 0;
	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		nb_chiffres += write(1, &s[i], 1);
		i++;
	}
	return (nb_chiffres);
}

int	ft_putnbr(int n, int *cnt)
{
	char		c;
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		c = '-';
		*cnt += write(1, &c, 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, cnt);
		ft_putnbr(nb % 10, cnt);
	}
	else
	{
		c = nb + '0';
		*cnt += write(1, &c, 1);
	}
	return (*cnt);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_format(char f, va_list paramsinfos)
{
	int	cnt;

	cnt = 0;
	if (f == 'd' || f == 'i')
		cnt = ft_putnbr(va_arg(paramsinfos, int), &cnt);
	if (f == 'u')
		cnt = print_unsigned(va_arg(paramsinfos, unsigned int), &cnt);
	else if (f == 's')
		cnt = ft_putstr(va_arg(paramsinfos, const char *));
	else if (f == 'c')
		cnt = ft_putchar(va_arg(paramsinfos, int));
	else if (f == 'x' || f == 'X')
		cnt = print_hexa_x(va_arg(paramsinfos, int), f, &cnt);
	else if (f == 'p')
		cnt = print_adress(paramsinfos, &cnt);
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		nb_print;
	va_list	paramsinfos;

	va_start(paramsinfos, s);
	i = -1;
	nb_print = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != '%')
			nb_print += write(1, &s[i], 1);
		else
		{
			if (s[i + 1] != '\0' && s[i + 1] == '%')
			{
				nb_print += write(1, &s[i + 1], 1);
			}
			else
				nb_print += print_format(s[i + 1], paramsinfos);
			i++;
		}
	}
	va_end(paramsinfos);
	return (nb_print);
}
