/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:17:58 by jorlopez          #+#    #+#             */
/*   Updated: 2024/12/05 10:17:58 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*buffer;
	char	*line;

	buffer = NULL;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = read_next(fd, buffer)) != NULL)
	{
		printf("Line: %s\n", line);
		if (line != buffer)
		{
			free(buffer);
			buffer = line;
		}
	}
	close(fd);
	if (buffer)
		free(buffer);
	return (0);
}
