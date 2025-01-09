/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:17:00 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/21 19:17:01 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(int board[10], int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col || board[i] - i == col - row || board[i] + i == col
			+ row)
			return (0);
		i++;
	}
	return (1);
}

void	print_solution(int board[10])
{
	int		i;
	char	character;

	i = 0;
	while (i < 10)
	{
		character = board[i] + '0';
		write(1, &character, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	solve(int board[10], int row, int *count)
{
	int	col;

	if (row == 10)
	{
		print_solution(board);
		(*count)++;
		return ;
	}
	col = 0;
	while (col < 10)
	{
		if (is_valid(board, row, col))
		{
			board[row] = col;
			solve(board, row + 1, count);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	printf("%d", ft_ten_queens_puzzle());
}
