/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:02:53 by obarais           #+#    #+#             */
/*   Updated: 2024/11/30 09:30:26 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int	ft_printf(const char *Format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_hexalower(unsigned int nb);
int	ft_hexaupper(unsigned int nb);
int	ft_unsigned_decimal(unsigned int nb);
int	ft_addressp(unsigned long nb);

#endif