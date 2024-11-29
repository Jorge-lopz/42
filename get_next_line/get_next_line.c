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

static	ft_get_line(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	buffer = ft_get_line(fd, buffer);
	// Print the
}

static	ft_get_line(int fd, char *buffer)
{
	while (!ft_strchr(buffer, '\n'))
	{
		if (read(fd, buffer, BUFFER_SIZE) < 0)
			return (0);
		buffer[BUFFER_SIZE] = '\0';
	}
	return (buffer);
}
