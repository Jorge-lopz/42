/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:41 by luestira          #+#    #+#             */
/*   Updated: 2024/08/18 20:50:42 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_matrix[4][4] = {{0}};

void	print_error(void);

int		checkargs(char *args);

int		check_borders(int *borders);

void	fill_matrix(int grid[4][4]);

void	print_matrix(void);

void	find_starting_nmb(int blocked_matrix[4][4], int *borders);

int		solve(int blocked_matrix[4][4], int row, int col, int *borders);

int		parse_input(char *str, int *borders);

int	main(int argc, char **argv)
{
	int	blocked_matrix[4][4];
	int	borders[16];

	fill_matrix(blocked_matrix);
	if (g_matrix[0][0] == 100)
		return (1);
	if (argc != 2 || !checkargs(argv[1]) || !parse_input(argv[1], borders)
		|| !check_borders(borders))
	{
		print_error();
		return (1);
	}
	find_starting_nmb(blocked_matrix, borders);
	if (!solve(blocked_matrix, 0, 0, borders))
		print_error();
	else
		print_matrix();
	return (0);
}
