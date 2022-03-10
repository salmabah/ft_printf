/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahraou <sbahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:36:04 by sbahraou          #+#    #+#             */
/*   Updated: 2022/02/25 02:42:02 by sbahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(long int n, int *cnt)
{
	char				*base;
	unsigned long int	nb;

	nb = n;
	base = "0123456789abcdef";
	if (nb < 16)
	{
		*cnt += write(1, &base[nb], 1);
	}
	else
	{
		print_hex(nb / 16, cnt);
		print_hex(nb % 16, cnt);
	}
	return (*cnt);
}

int	print_adress(va_list paramsinfos, int *cnt)
{
	long long	adr;
	void		*ptr;

	ptr = va_arg(paramsinfos, void *);
	adr = (long)ptr;
	*cnt += write(1, "0x", 2);
	return (print_hex(adr, cnt));
}
