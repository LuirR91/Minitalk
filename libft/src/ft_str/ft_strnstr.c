/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:34:00 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/15 15:24:12 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (*little == '\0')
		return ((char *)str);
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	while (i < len)
	{
		if (ft_strncmp((char *)&str[i], little, ft_strlen(little)) == 0)
		{
			if (i + ft_strlen(little) > len)
				return (NULL);
			return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
