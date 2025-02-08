/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:30:05 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/08 17:35:15 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
    ft_send_message(pid, argv[3]);
    return (0);
}