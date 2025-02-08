/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:30:05 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/08 21:05:57 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int  g_signal;

void    ft_send_char(int pid, char c_)
{
    unsigned char   octet;
    int             iter_bit;

    iter_bit = 8;
    octet = (unsigned char)c_;
    while(iter_bit--)
    {
        g_signal = 0;
        octet = (c_ >> iter_bit);
        ft_printf("octet = %d\n", octet);
        if (octet % 2 == 0)
        {
            if (kill(pid, SIGUSR1) == -1)
                exit(write(2, "Error in sending SIGUSR1\n", 6));
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
                exit(write(2, "Error in sending SIGUSR2\n", 6));
        }
        while(!g_signal)
            ;
    }
}

void    ft_send_message(int pid, char *message)
{
    int     iter;

    iter = 0;
    while (message[iter])
    {
        ft_send_char(pid, message[iter]);
        iter++;
    }
    ft_send_char(pid, '\0');
}

int     main(int argc, char **argv)
{
    int     pid;
    
    pid = ft_atoi(argv[1]);
    if (argc == 3)
    {
        ft_printf("pid = %d\n", pid);
        ft_printf("message = %s\n", argv[2]);
    }
    ft_send_message(pid, argv[2]);
    return (0);
}