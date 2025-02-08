/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:09:35 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/08 20:58:11 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_recieve_message(int signal_, siginfo_t *siginfo, void *context)
{
    (void)context;
    ft_printf("signal = %d\n", signal_);
    ft_printf("siginfo->si_pid = %d\n", siginfo->si_pid);
    if (signal_ == SIGUSR1)
        write(1, "0", 1);
    if (signal_ == SIGUSR2)
        write(1, "1", 1);
}

int     main()
{
    pid_t   pid;
    struct sigaction    sa;
    
    pid = getpid();
    ft_printf("pid = %d\n", pid);
    sa.sa_sigaction = &ft_recieve_message;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        ft_putendl_fd("Error in catching SIGUSR1", 2);
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        ft_putendl_fd("Error in catching SIGUSR2", 2);
    while (1)
        pause();
    return (0);
}