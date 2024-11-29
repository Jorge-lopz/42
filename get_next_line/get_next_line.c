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

static char	*ft_line(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (!buffer)
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	buffer = ft_line(fd, buffer);
	return (buffer);
}

static char	*ft_line(int fd, char *buffer)
{
	int	bytes_read;

	while (ft_strchr(buffer, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, 42);
		if (bytes_read == 0)
		{
			buffer[BUFFER_SIZE] = '\0';
			break ;
		}
	}
	return (buffer);
}
