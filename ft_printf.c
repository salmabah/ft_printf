/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahraou <sbahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:28:53 by sbahraou          #+#    #+#             */
/*   Updated: 2022/02/23 01:24:16 by sbahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include <limits.h>

int ft_putstr(const char *s)
{
	int	i;
	int	nb_chiffres;

	nb_chiffres = 0;
	i = 0;
	while (s[i])
	{
		nb_chiffres += write(1, &s[i], 1);
		i++;
	}
	return (nb_chiffres);
}

int ft_putnbr(int n, int *cnt)
{
	char c;
	long int nb;

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

int	ft_putunbr(unsigned int n, int *cnt)
{
	char		c;
	long int	nb; //a verifer

	nb = n;
	if (nb < 0)
	{
		c = '-';
		*cnt += write(1, &c, 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putunbr(nb / 10, cnt);
		ft_putunbr(nb % 10, cnt);
	}
	else
	{
		c = nb + '0';
		*cnt += write(1, &c, 1);
	}
	return (*cnt);
}

int	print_hexa_x(int nb, char f, int *cnt)
{
	char*	base;

	if (f =='x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb < 16)
	{
		*cnt += write(1, &base[nb], 1);
	}
	else
	{
		print_hexa_x(nb / 16, f, cnt);
		print_hexa_x(nb % 16, f, cnt);
	}
	return (*cnt);
}

int print_adress(long ptr, int *cnt)
{
	// long  *adr;

	// adr = (long *)ptr;
	printf("%lld", ptr);
	return (print_hexa_x(ptr, 'x', cnt));
}

// int print_unsigned(unsigned int nb, int *cnt)
// {
// 	int nb_chiffres;

// 	nb_chiffres = ft_putunbr(n, cnt);
	// nb_chiffres = 0;
	// if (nb < 0)
	// {
	// 	nb_chiffres++;
	// 	nb *= -1;
	// }
	// while (nb > 0)
	// {
	// 	nb_chiffres++;
	// 	nb /= 10;
	// }
	// return (nb_chiffres);
// }

// int print_digit(int n, char f)
// {
// 	int nb_chiffres;
// 	unsigned int nb;

// 	if (f == 'd' || f == 'i')
// 	{
// 		n = (int)va_arg(paramsinfos, int);
// 		nb_chiffres = ft_putnbr(n);
// 	}
// 	// nb_chiffres = 0;
// 	// if (n < 0)
// 	// {
// 	// 	nb_chiffres++;
// 	// 	n *= -1;
// 	// }
// 	// while (n > 0)
// 	// {
// 	// 	nb_chiffres++;
// 	// 	n /= 10;
// 	// }
// 	return (nb_chiffres);
// }

// int print_str(const char *s)
// {
// 	int n;
// 	char *s;

// 	n = 0;
// 	n = ft_putstr(s);
// 	return (n);
// }

int ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int print_format(char f, va_list paramsinfos)
{
	int cnt;

	cnt = 0;
	if (f == 'd' || f == 'i')
		cnt = ft_putnbr(va_arg(paramsinfos, int), &cnt);
	if (f == 'u')
		cnt = ft_putunbr(va_arg(paramsinfos, unsigned int), &cnt);
	else if (f == 's')
		cnt = ft_putstr(va_arg(paramsinfos, const char *));
	else if (f == 'c')
		cnt = ft_putchar(va_arg(paramsinfos, int));
	else if (f == 'x' || f == 'X')
		cnt = print_hexa_x(va_arg(paramsinfos, int), f, &cnt);
	else if (f == 'p')
		cnt = print_adress(va_arg(paramsinfos, long), &cnt);
	return (cnt);
}
//pxX?
int ft_printf(const char *s, ...)
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
			if (s[i] != '\0' && s[i] == '%')
			{
				nb_print++;
				write(1, &s[i], 1);
			}
			else
				nb_print += print_format(s[i], paramsinfos);
		}
		i++;
	}
	va_end(paramsinfos);
	return (nb_print);
}

int main(int argc, char *argv[])
{
	// ft_printf("Hello %c%%",'c');
	char c = 'S';
	printf("  %d", ft_printf("%p", &c));
	printf("\n");
	printf("  %d", printf("%p", &c));
}
