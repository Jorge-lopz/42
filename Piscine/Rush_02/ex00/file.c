/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:18:46 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/25 21:18:47 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "rush.h"

#include <stdio.h>

int	open_file(char *path)
{
	int	file_id;
	
	file_id = open(path, O_RDONLY);	
	if (file_id == -1)
	{
		putstr("Dict Error\n");
	}
	return (file_id);
}

char	*read_file(int file_id)
{
	int	read_bytes;
	int	total_bytes;
	char	*temp[1];
	char	*g_file_content;
	
	read_bytes = 1;
	total_bytes = 0;
	while (read_bytes > 0)
	{
		read_bytes = read(file_id, temp, 1);
		total_bytes++;
	}
	if (close_file(file_id) == 0)
		return (0);
	file_id = open_file("numbers.dict");
	g_file_content = malloc(total_bytes + 1);
	if (g_file_content == NULL)
		write(1, "ERROR: Memory allocation failed\n", 32);
	read(file_id, g_file_content, total_bytes);
	return (g_file_content);
}

int	close_file(int file_id)
{
	if (close(file_id) == -1)
	{
		putstr("Error\n");
		return (0);
	}
	return (1);
}

void	print_num(char *num)
{
	if ()
	{
	
	}
}
