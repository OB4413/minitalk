/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:39:30 by obarais           #+#    #+#             */
/*   Updated: 2025/02/12 16:45:16 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		bit = 0;
	static pid_t	last_pid = 0;

	(void)context;
	if (last_pid != info->si_pid)
	{
		c = 0;
		bit = 0;
		last_pid = info->si_pid;
	}
	if (sig == SIGUSR2)
		c |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	act.sa_sigaction = handle_signal;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
