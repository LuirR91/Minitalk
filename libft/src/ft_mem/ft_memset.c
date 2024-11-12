/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:00:19 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/06 10:17:22 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = str;
	while (n)
	{
		*ptr++ = c;
		n--;
	}
	return (str);
}

/*
int	main()
{
	char str [] = "abc";

	ft_memset(str, "o", 3);
	printf("%s\n", str);
	return (0);
}
*/
