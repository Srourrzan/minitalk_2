/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:30:23 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/09 20:12:09 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/header/ft_printf.h"
#include "libft/header/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_message
{
    int             pid;
    int             bit_count;
    unsigned char   buff;
}               t_message;

void            ft_send_message(int pid, char *message);
void            ft_send_char(int pid, char c_);
void            ft_recieve_message(int signal_, siginfo_t *siginfo, void *context);
void            ft_g_set(int signal_);
t_message       *ft_init_message(int pid);

#endif