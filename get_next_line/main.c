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
	char	*line;
	int		i;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	i = 1;
	line = get_next_line(fd);
	printf("Line %d: %s", i, line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		printf("Line %d: %s", i, line);
		i++;
	}
	close(fd);
	return (0);
}
