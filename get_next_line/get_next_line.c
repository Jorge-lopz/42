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
	char		*temp;
	int			end;

	if (!buffer || fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	temp = ft_read(fd, buffer); // Read at least once
	buffer = ft_strjoin(buffer, temp);
	end = temp[ft_strlen(temp) - 1] == '\0';
	free(temp);
	temp = NULL;
	while (!end)
	{
		temp = ft_read(fd, buffer);
		buffer = ft_strjoin(buffer, temp);
		printf("BUFFER: %s\n", buffer);
		end = temp[ft_strlen(temp) - 1] == '\0';
		free(temp);
		temp = NULL;
	}
	return (buffer);
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
		return (buffer); // TODO
	}
	else if (bytes_read < BUFFER_SIZE)
		temp[bytes_read] = '\0';
	return (temp);
}
