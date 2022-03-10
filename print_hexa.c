/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahraou <sbahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:37:27 by sbahraou          #+#    #+#             */
/*   Updated: 2022/02/25 02:41:11 by sbahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_x(int n, char f, int *cnt)
{
	char			*base;
	unsigned int	nb;

	nb = n;
	if (f == 'x')
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
