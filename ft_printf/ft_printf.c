/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:30:03 by obarais           #+#    #+#             */
/*   Updated: 2024/11/30 10:02:41 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_lst(va_list lst, char Format)
{
	int	res;

	res = 0;
	if (Format == 'c')
		res += ft_putchar(va_arg(lst, int));
	else if (Format == 's')
		res += ft_putstr(va_arg(lst, char *));
	else if (Format == 'p')
		res += ft_addressp(va_arg(lst, unsigned long));
	else if (Format == 'd' || Format == 'i')
		res += ft_putnbr(va_arg(lst, int));
	else if (Format == 'u')
		res += ft_unsigned_decimal(va_arg(lst, unsigned int));
	else if (Format == 'x')
		res += ft_hexalower(va_arg(lst, unsigned int));
	else if (Format == 'X')
		res += ft_hexaupper(va_arg(lst, unsigned int));
	else if (Format == '%')
		res += ft_putchar(Format);
	return (res);
}

int	ft_printf(const char *Format, ...)
{
	int		i;
	int		res;
	va_list	lst;

	i = 0;
	res = 0;
	va_start(lst, Format);
	if (Format == NULL)
	{
		va_end(lst);
		return (-1);
	}
	while (Format[i])
	{
		if (Format[i] == '%')
		{
			i++;
			res += ft_print_lst(lst, Format[i]);
		}
		else if (Format[i] != '%')
			res += ft_putchar(Format[i]);
		i++;
	}
	va_end(lst);
	return (res);
}
