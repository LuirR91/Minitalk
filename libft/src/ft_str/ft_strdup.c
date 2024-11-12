/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:39:04 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/06 10:18:13 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*clone;

	size = ft_strlen(src);
	clone = malloc(sizeof (char) * (size + 1));
	if (clone == NULL)
		return (NULL);
	return (ft_strcpy(clone, (char *)src));
}

/*
int	main()
{
	char *s1 = "123";
	char *s2 = ft_strdup(s1);
	
	printf("%s\n", s2);
}
*/
