/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:33:23 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/06 10:17:06 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	chr;

	i = 0;
	str = (char *)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*
int	main()
{
	char	s[] = "abcdefg";
	char	*res;
	res = ft_memchr(s, 'b', 5);

	printf("%s\n", res);
	return (0);
}
*/
