/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:55:13 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/06 10:18:18 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
void    myfunction(unsigned int i, char *c)
{
	printf("My inner function: index = %d and the string is %s\n", i, c);
	*c = ft_toupper((unsigned char)*c);
}

int	main()
{
	char	str[] = "heyhey";
	
	printf("Before striteri str is %s\n", str);
	ft_striteri(str, myfunction);
	printf("After striteri str is %s\n", str);
	return (0);
}
*/
