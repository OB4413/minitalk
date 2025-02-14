/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:33:33 by obarais           #+#    #+#             */
/*   Updated: 2025/02/14 21:51:46 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	g_i = 0;

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (0);
	return (nbr * sign);
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_i = 1;
}

void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_i = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_i)
			usleep(50);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0 || pid == -1)
	{
		write(2, "Invalid PID\n", 12);
		return (1);
	}
	signal(SIGUSR1, sig_handler);
	i = 0;
	while (argv[2][i])
		send_char(pid, argv[2][i++]);
	send_char(pid, '\0');
	return (0);
}
