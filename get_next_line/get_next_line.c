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

char	*free_mem(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (free_mem(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (free_mem(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	free_mem(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*readbuf(int fd, char *storage)
{
	int		rid;
	char	*buffer;

	rid = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_mem(&storage));
	buffer[0] = '\0';
	while (rid > 0 && !ft_strchr(buffer, '\n'))
	{
		rid = read(fd, buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			buffer[rid] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (rid == -1)
		return (free_mem(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = readbuf(fd, storage);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (free_mem(&storage));
	storage = clean_storage(storage);
	return (line);
}
