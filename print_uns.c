/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahraou <sbahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:45:10 by sbahraou          #+#    #+#             */
/*   Updated: 2022/02/25 01:09:45 by sbahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n, int *cnt)
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
		print_unsigned(nb / 10, cnt);
		print_unsigned(nb % 10, cnt);
	}
	else
	{
		c = nb + '0';
		*cnt += write(1, &c, 1);
	}
	return (*cnt);
}
