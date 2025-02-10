/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:44:32 by obarais           #+#    #+#             */
/*   Updated: 2025/02/10 14:38:14 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

void handle_signal(int sig)
{
    static char c = 0;
    static int bit = 0;

    if (sig == SIGUSR2)
        c |= (1 << bit);

    bit++; 

    if (bit == 8)
    {
        write(1, &c, 1);
        if (c == '\0')
            write(1, "\n", 1);
        c = 0;
        bit = 0;
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    printf("PID: %d\n", pid);
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    while (1)
        pause();
}