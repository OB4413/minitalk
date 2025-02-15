/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:20:32 by obarais           #+#    #+#             */
/*   Updated: 2024/11/25 16:12:26 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaupper(unsigned int nb)
{
	int		res;
	char	*h;

	h = "0123456789ABCDEF";
	res = 0;
	if (nb >= 16)
	{
		res += ft_hexaupper(nb / 16);
		res += ft_hexaupper(nb % 16);
	}
	else
		res += ft_putchar(h[nb]);
	return (res);
}
