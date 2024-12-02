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
		temp = ft_strdup(newline + 1);
		free(*buffer); // Free old buffer after the new one is assigned
		*buffer = temp;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer); // Free the buffer if no newline is found
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
		free(read_buf); // Free read_buf if no data is read
		return (bytes_read);
	}
	read_buf[bytes_read] = '\0';
	temp = ft_strjoin(*buffer, read_buf);
	free(read_buf); // Free read_buf after using it
	if (!temp)
		return (-1);
	free(*buffer); // Free the old buffer before assigning the new one
	*buffer = temp;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*newline;
	int			read_status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup(""); // Initialize the buffer on first call
	newline = ft_strchr(buffer, '\n');
	while (newline == NULL)
	{
		read_status = read_to_buffer(fd, &buffer);
		if (read_status <= 0)
		{
			if (buffer && *buffer)
				return (extract_line(&buffer, NULL));
			// Return remaining content
			return (NULL);
			// No data read and buffer is empty
		}
		newline = ft_strchr(buffer, '\n');
	}
	return (extract_line(&buffer, newline));
}
