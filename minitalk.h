/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:30:23 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/08 21:07:13 by rsrour           ###   ########.fr       */
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

void    ft_send_message(int pid, char *message);
void    ft_send_char(int pid, char c_);

#endif