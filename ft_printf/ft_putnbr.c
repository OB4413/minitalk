/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:06:21 by obarais           #+#    #+#             */
/*   Updated: 2024/12/01 15:28:35 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
	{
		res = res + ft_putstr("-2147483648");
	}
	else if (n < 0)
	{
		res = res + ft_putchar('-');
		res = res + ft_putnbr(n * (-1));
	}
	else if (n > 9)
	{
		res = res + ft_putnbr(n / 10);
		res = res + ft_putnbr(n % 10);
	}
	else
		res = res + ft_putchar(n + '0');
	return (res);
}
