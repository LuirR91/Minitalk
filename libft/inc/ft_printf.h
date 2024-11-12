/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:43:26 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/21 14:30:13 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);

int		ft_print_char(int c);
int		ft_print_str(const char *str);

int		ft_print_digits(long nbr, int base);
int		ft_print_upper_digits(long nbr, int base);

int		ft_print_ptr(unsigned long long ptr);
int		ft_print_unsigned(unsigned int num);

#endif
