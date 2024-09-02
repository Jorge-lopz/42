/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorita- <lzorita-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:28:04 by lzorita-          #+#    #+#             */
/*   Updated: 2024/08/11 20:28:15 by lzorita-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x <= 0 || y <= 0)
	{
		write(1, "ERROR: Dimensions need to be greater than 0\n", 44);
		return ;
	}
	row = 0;
	while (row++ < y)
	{
		col = 0;
		while (col++ < x)
		{
			if ((row == 1) && (col == 1 || col == x))
				ft_putchar('A');
			else if ((row == y) && (col == 1 || col == x))
				ft_putchar('C');
			else if (row == 1 || row == y || col == 1 || col == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
