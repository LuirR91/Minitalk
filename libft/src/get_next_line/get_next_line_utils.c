/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:56:22 by luiribei          #+#    #+#             */
/*   Updated: 2024/10/22 13:59:57 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;
	char	*s_final;

	len_s1 = ft_gnl_strlen(s1);
	len_s2 = ft_gnl_strlen(s2);
	s_final = (char *)malloc(len_s1 + len_s2 + 1);
	if (s_final == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (i++ < (len_s1 - 1))
		s_final[i] = s1[i];
	while (j++ < (len_s2 - 1))
	{
		s_final[i] = s2[j];
		i++;
	}
	s_final[i] = '\0';
	if (s1)
		free (s1);
	return (s_final);
}

int	ft_is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_clean(char *current_line, char *read_content)
{
	int	pos;
	int	i;

	pos = ft_is_newline(current_line);
	if (pos != -1)
		current_line[pos + 1] = '\0';
	i = 0;
	pos = ft_is_newline(read_content);
	if (pos != -1)
	{
		pos++;
		while (read_content[pos])
		{
			read_content[i++] = read_content[pos++];
		}
	}
	while (i < BUFFER_SIZE)
	{
		read_content[i++] = '\0';
	}
	return (current_line);
}
