/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luestira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:22 by luestira          #+#    #+#             */
/*   Updated: 2024/08/18 20:50:23 by luestira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	g_matrix[4][4];

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_matrix(void)
{
	int		row;
	int		col;
	char	num_write;

	if (g_matrix[0][0] == 20)
		return ;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			num_write = '0' + g_matrix[row][col];
			write(1, &num_write, 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	parse_input(char *str, int *borders)
{
	int		i;
	int		len;
	char	*str_copy;

	len = 0;
	str_copy = str;
	while (*str_copy)
	{
		if (*str_copy != ' ')
			len++;
		str_copy++;
	}
	if (len != 16)
		return (0);
	i = 0;
	while (i < 16)
	{
		if (str[i * 2] >= '1' && str[i * 2] <= '4')
			borders[i] = str[i * 2] - '0';
		else
			return (0);
		i++;
	}
	return (1);
}

void	fill_matrix(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}
