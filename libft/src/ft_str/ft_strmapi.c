/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:35:28 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/06 10:18:40 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

/*
char	my_func(unsigned int i, char c)
{
	printf("My function: index = %d and %c\n", i, c);
	return ('c' - 1);
}

int	main()
{
	char	*str;
	char	*newstr;

	str = "Hello";
	newstr = ft_strmapi(str, my_func);

	printf("%s\n", newstr);
	free (newstr);
	return (0);
}
*/
