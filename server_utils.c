/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:58:31 by rsrour            #+#    #+#             */
/*   Updated: 2025/02/09 21:23:17 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message       *ft_init_message(int pid)
{
    t_message   *new;

    new = malloc(sizeof(t_message));
    if (!new)
        return (NULL);
    new->buff = 0;
    new->bit_count = 1;
    new->buff = pid;
    return (new);
}
