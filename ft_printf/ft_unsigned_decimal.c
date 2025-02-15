/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:39:54 by obarais           #+#    #+#             */
/*   Updated: 2024/11/28 21:22:23 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_decimal(unsigned int nb)
{
	int	res;

	res = 0;
	if (nb > 9)
	{
		res += ft_unsigned_decimal(nb / 10);
		res += ft_unsigned_decimal(nb % 10);
	}
	else
		res += ft_putchar(nb + '0');
	return (res);
}
