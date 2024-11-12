/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:40:18 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/06 10:23:23 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
int	main()
{
	char	str[] = "zeros";
	
	printf("%s\n", str);
	ft_bzero(str, 5);
	printf("%s\n", str);
	return (0);
}
*/
