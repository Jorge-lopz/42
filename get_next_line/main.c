/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:39:51 by jorlopez          #+#    #+#             */
/*   Updated: 2024/11/13 20:39:51 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("empty.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	// Read and print lines until EOF or error
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // Print the line
		free(line);
		// Don't forget to free the memory allocated for the line
	}
	close(fd); // Close the file descriptor
	return (0);
}
