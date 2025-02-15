/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:47:52 by obarais           #+#    #+#             */
/*   Updated: 2024/11/25 17:34:04 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalower(unsigned int nb)
{
	int		res;
	char	*h;

	h = "0123456789abcdef";
	res = 0;
	if (nb >= 16)
	{
		res += ft_hexalower(nb / 16);
		res += ft_hexalower(nb % 16);
	}
	else
		res += ft_putchar(h[nb]);
	return (res);
}
