/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:13:54 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/28 18:14:00 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*get_map(char *path, int *rows, int *cols)
{
	char	*text;
	int		start;

	text = get_text(path);
	if (text == NULL)
		return ("0");
	start = 0;
	while (text[start] && text[start] != '\n')
		start++;
	*rows = get_rows(start, text);
	if (*rows == -1)
		return (NULL);
	if (get_legend(text, *rows) == -1)
		return (NULL);
	*cols = ((get_len(text) - (start + 1)) / *rows) - 1;
	if (generate_map(*rows, *cols, start++, text) == -1)
		return (NULL);
	return (text);
}

int	get_res_map(int rows, int cols)
{
	int	i;
	int	j;

	g_res_map = (int **)malloc(rows * sizeof(int *));
	if (g_res_map == NULL)
		return (-1);
	i = -1;
	while (++i < rows)
	{
		g_res_map[i] = (int *)malloc(cols * sizeof(int));
		if (g_res_map[i] == NULL)
			return (-1);
		j = -1;
		while (++j < cols)
		{
			g_res_map[i][j] = -1;
			if (g_map[i][j] == g_obstacle)
				g_res_map[i][j] = 0;
			else if (g_map[i][j] != g_obstacle && (i == 0 || j == 0))
				g_res_map[i][j] = 1;
		}
	}
	return (0);
}

void	start_solve(char *text, int rows, int cols)
{
	if (*text != '0')
	{
		get_res_map(rows, cols);
		solve_bsq(rows, cols);
	}
}

void	solve_bsq(int rows, int cols)
{
	int	i;
	int	j;
	int	max_square;
	int	max_ij[2];

	max_square = 0;
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (g_res_map[i][j] == -1)
				g_res_map[i][j] = get_min_around(i, j) + 1;
			if (g_res_map[i][j] > max_square)
			{
				max_square = g_res_map[i][j];
				max_ij[0] = i - max_square + 1;
				max_ij[1] = j - max_square + 1;
			}
		}
	}
	print_bsq(max_square, max_ij, rows, cols);
}

void	print_bsq(int max_square, int max_ij[2], int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (i >= max_ij[0] && i < (max_ij[0] + max_square)
				&& j >= max_ij[1] && j < (max_ij[1] + max_square))
				write(1, &g_result, 1);
			else
				write(1, &g_map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
