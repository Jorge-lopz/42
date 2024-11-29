/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:18:54 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/25 21:18:55 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*g_file_content;

int	main(int argc, char *argv[])
{
	int		file_id;
	char	*num;
	char	*path;

	if (!(argc == 2 || argc == 3))
	{
		putstr("Error\n");
		return (1);
	}
	// Check valid number
	num = argv[1]
		// Check valid dictionary
		path = "numbers.dict";
	if (argc == 3)
	{
		path = argv[1];
		num = argv[2];
	}
	file_id = open_file(path);
	if (file_id == -1)
		return (1);
	g_file_content = read_file(file_id);
	if (g_file_content == NULL)
		return (1);
	print_num(num);
}
