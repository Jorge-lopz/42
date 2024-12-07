/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:38:55 by jorlopez          #+#    #+#             */
/*   Updated: 2024/12/02 18:02:01 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_mem(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	*remove_last(char *buffer)
{
	char	*new_buffer;
	char	*ptr;
	int		len;

	ptr = ft_strchr(buffer, '\n');
	if (!ptr)
	{
		new_buffer = NULL;
		return (free_mem(buffer));
	}
	else
		len = (ptr - buffer) + 1;
	if (!buffer[len])
		return (free_mem(buffer));
	new_buffer = ft_substr(buffer, len, ft_strlen(buffer) - len);
	free_mem(buffer);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

char	*select_next(char *buffer)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(buffer, '\n');
	len = (ptr - buffer) + 1;
	line = ft_substr(buffer, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_next(int fd, char *buffer)
{
	int		rid;
	char	*temp_buffer;

	rid = 1;
	temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (free_mem(buffer));
	temp_buffer[0] = '\0';
	while (rid > 0 && !ft_strchr(temp_buffer, '\n'))
	{
		rid = read(fd, temp_buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			temp_buffer[rid] = '\0';
			buffer = ft_strjoin(buffer, temp_buffer);
		}
	}
	free(temp_buffer);
	if (rid == -1)
		return (free_mem(buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0)
		return (NULL);
	if ((buffer && !ft_strchr(buffer, '\n')) || !buffer)
		buffer = read_next(fd, buffer);
	if (!buffer)
		return (NULL);
	line = select_next(buffer);
	if (!line)
		return (free_mem(buffer));
	buffer = remove_last(buffer);
	return (line);
}
