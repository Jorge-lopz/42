/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorita- <lzorita-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:29:18 by lzorita-          #+#    #+#             */
/*   Updated: 2024/08/11 20:29:27 by lzorita-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_row(char *pattern, int x)
{
	int	col;

	col = 0;
	while (col++ < x)
	{
		if (col == 1)
			ft_putchar(pattern[0]);
		else if (col == x)
			ft_putchar(pattern[2]);
		else
			ft_putchar(pattern[1]);
	}
	write (1, "\n", 1);
}

void	rush(int x, int y)
{
	char	*frst;
	char	*midd;
	char	*last;
	int		row;

	frst = "/*\\";
	midd = "* *";
	last = "\\*/";
	if (x <= 0 || y <= 0)
	{
		write(1, "ERROR: Dimensions need to be greater than 0\n", 44);
		return ;
	}
	row = 0;
	while (row++ < y)
	{
		if (row == 1)
			ft_row(frst, x);
		else if (row == y)
			ft_row(last, x);
		else
			ft_row(midd, x);
	}
}
