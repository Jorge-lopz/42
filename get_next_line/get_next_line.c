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

static char	*extract_line(char **buffer, char *newline)
{
	char	*line;
	char	*temp;

	if (newline)
	{
		line = ft_substr(*buffer, 0, newline - *buffer + 1);
		if (!line)
			return (NULL);
		temp = ft_strdup(newline + 1);
		if (!temp)
			return (NULL);
		free(*buffer);
		*buffer = temp;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static int	read_to_buffer(int fd, char **buffer)
{
	char	*temp;
	char	*read_buf;
	ssize_t	bytes_read;

	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (-1);
	bytes_read = read(fd, read_buf, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(read_buf);
		return (bytes_read);
	}
	read_buf[bytes_read] = '\0';
	temp = ft_strjoin(*buffer, read_buf);
	free(read_buf);
	if (!temp)
	{
		free(*buffer);
		*buffer = NULL;
		return (-1);
	}
	free(*buffer);
	*buffer = temp;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*newline;
	int			read_status;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	while (1)
	{
		newline = ft_strchr(buffer, '\n');
		if (newline)
			return (extract_line(&buffer, newline));
		read_status = read_to_buffer(fd, &buffer);
		if (read_status < 0)
		{
			free(buffer); // Free on read error
			buffer = NULL;
			return (NULL);
		}
		if (read_status == 0)
		{
			if (buffer && *buffer)
			{
				line = extract_line(&buffer, NULL);
				free(buffer);
				buffer = NULL;
				return (line);
			}
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
	}
}
