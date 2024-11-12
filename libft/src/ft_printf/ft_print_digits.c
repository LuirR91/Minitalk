/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:47:29 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/21 14:52:37 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digits(long nbr, int base)
{
	int		i;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (nbr < 0)
	{
		write (1, "-", 1);
		return (ft_print_digits(-nbr, base) + 1);
	}
	else if (nbr < base)
		return (ft_print_char(symbols[nbr]));
	else
	{
		i = ft_print_digits(nbr / base, base);
		return (i + ft_print_digits(nbr % base, base));
	}
}
