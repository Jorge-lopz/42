/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:14:44 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/28 18:14:45 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**g_res_map;
char	**g_map;
char	g_normal;
char	g_obstacle;
char	g_result;

int	main(int argc, char *argv[])
{
	int		rows;
	int		cols;
	int		i;
	char	*text;

	i = 1;
	if (argc == 1)
		i = 0;
	while (i < argc)
	{
		if (i == 0)
			text = console_input(&rows, &cols);
		else
			text = get_map(argv[i], &rows, &cols);
		if (text == NULL)
			write (1, "map error", 10);
		else
			start_solve(text, rows, cols);
		i++;
		if (i < argc)
			write(1, "\n", 1);
	}
	frees(text, rows);
	return (0);
}
