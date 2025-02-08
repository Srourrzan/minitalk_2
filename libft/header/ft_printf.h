/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:22:28 by rsrour            #+#    #+#             */
/*   Updated: 2024/10/26 20:22:31 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *fmt, ...);
int		ft_convert_decimel_to_hexa_p(unsigned long number);
int		ft_convert_decimel_to_hexa_x(unsigned int number, char *str);
int		ft_convert_signed_to_unsigned(unsigned int number);
int		print_signed_numbers(int number, int num_char);
int		print_str(char *str, int num_char);
int		print_ptr(unsigned long ptr_add, int num_char);
int		print_hexa(unsigned int x_value, int num_char, char type);
int		print_unsigned(unsigned int u_value, int num_char);
char	*str_toupper(char *data);

#endif
