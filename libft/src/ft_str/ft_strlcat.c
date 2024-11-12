/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:13:11 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/06 10:51:38 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;

	s = ft_strlen(src);
	if (size == 0)
		return (s);
	d = ft_strlen(dst);
	if (d >= size)
		return (s + size);
	dst += d;
	size -= d;
	while (*src && --size)
		*dst++ = *src++;
	*dst = '\0';
	return (d + s);
}

/*
int	main()
{
	char	src[] = "12345678";
	char	dest[] = "123456";

	printf("%zu\n", ft_strlcat(dest, src, 7));
	return (0);
}
*/
