/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:32:19 by jorlopez          #+#    #+#             */
/*   Updated: 2024/12/02 19:32:19 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
