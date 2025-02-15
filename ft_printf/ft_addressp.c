/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addressp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:27:05 by obarais           #+#    #+#             */
/*   Updated: 2024/12/01 15:20:19 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexalow(unsigned long nb)
{
	int		res;
	char	*h;

	h = "0123456789abcdef";
	res = 0;
	if (nb >= 16)
	{
		res += ft_hexalow(nb / 16);
		res += ft_hexalow(nb % 16);
	}
	else
		res += ft_putchar(h[nb]);
	return (res);
}

int	ft_addressp(unsigned long nb)
{
	int	res;

	res = 0;
	if (nb == 0)
	{
		res += ft_putstr("(nil)");
		return (res);
	}
	res += ft_putstr("0x");
	res += ft_hexalow(nb);
	return (res);
}
