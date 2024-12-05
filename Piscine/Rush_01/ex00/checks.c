/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:13 by luestira          #+#    #+#             */
/*   Updated: 2024/08/18 20:50:14 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_matrix[4][4];

int	is_valid(int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_matrix[row][i] == num || g_matrix[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	visibility_count(int *line, int direction)
{
	int	i;
	int	max_height;
	int	visible_count;

	max_height = 0;
	visible_count = 0;
	if (direction == 0)
		i = 0;
	else
		i = 3;
	while (i >= 0 && i < 4)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		if (direction == 0)
			i++;
		else
			i--;
	}
	return (visible_count);
}

int	check_visibility(int *borders, int row, int col)
{
	int	line[4];
	int	i;

	if (col == 3)
	{
		i = -1;
		while (i++ < 3)
			line[i] = g_matrix[row][i];
		if (visibility_count(line, 0) != borders[8 + row]
			|| visibility_count(line, 1) != borders[12 + row])
			return (0);
	}
	if (row == 3)
	{
		i = -1;
		while (i++ < 3)
			line[i] = g_matrix[i][col];
		if (visibility_count(line, 0) != borders[col] || visibility_count(line,
				1) != borders[4 + col])
			return (0);
	}
	return (1);
}

int	checkargs(char *args)
{
	int	last_char;

	while (*args)
	{
		if (*args == ' ')
		{
			if (last_char == 0)
				return (0);
			last_char = 0;
		}
		else if (*args >= '0' && *args <= '9')
		{
			if (last_char == 1 || *args < '1' || *args > '4')
				return (0);
			last_char = 1;
		}
		else
			return (0);
		args++;
	}
	return (1);
}

int	check_borders(int *borders)
{
	int	i;
	int	offset;
	int	counter1;

	i = -1;
	offset = 0;
	counter1 = 0;
	while (i++ < 3)
	{
		if (borders[i * 4 + offset] == 1)
			counter1++;
		offset++;
		if (offset < 4)
			i--;
		if (offset == 4)
		{
			if (counter1 != 1)
				return (0);
			counter1 = 0;
			offset = 0;
		}
	}
	return (1);
}
