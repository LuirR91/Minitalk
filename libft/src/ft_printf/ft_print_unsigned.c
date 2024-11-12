/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:12:27 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/24 11:17:51 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char	*ft_uitoa(unsigned int num)
{
	char	*str;
	int		len;

	len = ft_numlen(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = num % 10 + 48;
		num = num / 10;
		len--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int num)
{
	int		i;
	char	*n;

	i = 0;
	if (num == 0)
		i += write(1, "0", 1);
	else
	{
		n = ft_uitoa(num);
		i += ft_print_str(n);
		free(n);
	}
	return (i);
}
