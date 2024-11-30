/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:38:55 by jorlopez          #+#    #+#             */
/*   Updated: 2024/11/13 20:38:55 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			end;
	int			i;

	if (!buffer || fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	line = NULL;
	end = 0;
	while (!end)
	{
		if (!buffer) // Read at least once if the buffer is empty
			buffer = ft_read(fd, buffer);
		// Find the position of the newline character
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		// Allocate memory for the line
		line = ft_substr(buffer, 0, i + (buffer[i] == '\n' ? 1 : 0));
		if (buffer[i] == '\n')
			end = 1;
		// If there's more data to read after the newline, move the buffer
		if (end)
			buffer = ft_strdup(&buffer[i + 1]);
		else
			buffer = ft_read(fd, buffer);
	}
	return (line);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*temp;
	int		bytes_read;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (0);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(temp);
		return (buffer); // Return remaining buffer or NULL
	}
	else
	{
		temp[bytes_read] = '\0';
		return (temp);
	}
}
