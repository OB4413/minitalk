/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:33:06 by obarais           #+#    #+#             */
/*   Updated: 2025/02/10 13:43:46 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <limits.h>

size_t	ft_atoi(const char *str)
{
	size_t	i;
	int		a;
	long	num;

	i = 0;
	a = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			a = a * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > (LONG_MAX - (str[i] - 48)) / 10)
			return (-a * (a == 1));
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return ((int)num * a);
}

void    single_bit(int pid, char c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        i++;
    }
}

int main(int ac, char **av)
{
    int i;
    int pid;

    i = 0;
    if (ac != 3)
    {
        write(2, "usage: ./client [pid] [message]\n", 31);
        return (1);
    }
    pid = ft_atoi(av[1]);
    while (av[2][i])
    {
        single_bit(pid, av[2][i]);
        i++;
    }
    return (0);
}