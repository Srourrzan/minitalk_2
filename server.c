/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:09:35 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/09 20:17:25 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_recieve_message(int signal_, siginfo_t *siginfo, void *context)
{
    static t_message    *head;
    t_message           *curr;
    
    if (head == NULL)
        head = ft_init_message(siginfo->si_pid);
    (void)context;
    if (signal_ == SIGUSR1)
        curr->buff |= 1;
    curr->bit_count++;
    if (signal_ == SIGUSR2)
        write(1, "1", 1);
    kill(siginfo->si_pid, SIGUSR1);
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
