/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:50:18 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/15 15:22:48 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*new_dest;
	char	*new_src;

	new_dest = ((char *)dest);
	new_src = ((char *)src);
	if (!new_dest && !new_src)
		return (NULL);
	if (new_dest > new_src)
	{
		while (n > 0)
		{
			n--;
			new_dest[n] = new_src[n];
		}
	}
	else
	{
		ft_memcpy(new_dest, new_src, n);
	}
	return (dest);
}
/*
int	main()
{
	char	src[] = "hello";
	char	dest[10] = "lala";

	ft_memmove(dest, src, 3);
	printf("%s\n", dest);
	return (0);
}
*/
