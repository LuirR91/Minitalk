/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:29:32 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/11 21:45:21 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	read_content[BUFFER_SIZE + 1];
	char		*current_line;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	current_line = NULL;
	while (ft_is_newline(current_line) == -1)
	{
		if (read_content[0] == '\0')
		{
			read_bytes = read(fd, read_content, BUFFER_SIZE);
			if (read_bytes <= 0)
			{
				if (read_bytes == 0)
					return (current_line);
				free(current_line);
				return (NULL);
			}
			read_content[read_bytes] = '\0';
		}
		current_line = ft_gnl_strjoin(current_line, read_content);
		ft_clean (current_line, read_content);
	}
	return (current_line);
}
