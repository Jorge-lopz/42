/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:00 by luestira          #+#    #+#             */
/*   Updated: 2024/08/18 20:50:03 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_matrix[4][4];

void		print_matrix(void);

int			is_valid(int row, int col, int num);

int			check_visibility(int *borders, int row, int col);

void	place_definitive_1234(int blocked[4][4], int row, int col, int i)
{
	while (i >= 0 && i < 4)
	{
		if (row == 0 || row == 3)
		{
			blocked[i][col] = 1;
			if (row == 0)
				g_matrix[i][col] = i + 1;
			else
				g_matrix[i][col] = 4 - i;
		}
		else if (col == 0 || col == 3)
		{
			blocked[row][i] = 1;
			if (col == 0)
				g_matrix[row][i] = i + 1;
			else
				g_matrix[row][i] = 4 - i;
		}
		if (row == 0 || col == 0)
			i++;
		else if (row == 3 || col == 3)
			i--;
	}
}

void	place_definitive_4(int blocked[4][4], int row, int col)
{
	g_matrix[row][col] = 4;
	blocked[row][col] = 1;
}

void	find_starting_nmb(int blocked_matrix[4][4], int *borders)
{
	int	i;

	i = -1;
	while (i++ < 3)
	{
		if (borders[i] == 1)
			place_definitive_4(blocked_matrix, 0, i);
		if (borders[4 + i] == 1)
			place_definitive_4(blocked_matrix, 3, i);
		if (borders[8 + i] == 1)
			place_definitive_4(blocked_matrix, i, 0);
		if (borders[12 + i] == 1)
			place_definitive_4(blocked_matrix, i, 3);
	}
}

int	solve(int blocked_matrix[4][4], int row, int col, int *borders)
{
	int	num;

	if (row == 4)
		return (1);
	if (col == 4)
		return (solve(blocked_matrix, row + 1, 0, borders));
	if (blocked_matrix[row][col] == 1 && check_visibility(borders, row,
			col) == 1)
		return (solve(blocked_matrix, row, col + 1, borders));
	num = 1;
	while (num <= 4)
	{
		if (is_valid(row, col, num))
		{
			g_matrix[row][col] = num;
			if (check_visibility(borders, row, col) == 1)
			{
				if (solve(blocked_matrix, row, col + 1, borders))
					return (1);
			}
			g_matrix[row][col] = 0;
		}
		num++;
	}
	return (0);
}
