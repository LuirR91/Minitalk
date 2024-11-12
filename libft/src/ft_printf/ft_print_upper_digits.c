/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_digits.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:56:32 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/21 14:54:28 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upper_digits(long nbr, int base)
{
	int		i;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_print_upper_digits(-nbr, base) + 1);
	}
	else if (nbr < base)
		return (ft_print_char(symbols[nbr]));
	else
	{
		i = ft_print_upper_digits(nbr / base, base);
		return (i + ft_print_upper_digits(nbr % base, base));
	}
}
