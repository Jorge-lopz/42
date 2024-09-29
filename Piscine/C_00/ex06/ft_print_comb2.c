/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:33:57 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/11 11:34:00 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  Create a function that displays all different combination of two two digits 
  numbers (XX XX) between 00 and 99, listed by ascending order.
*/

#include <unistd.h>

void	print_num(int num)
{
	char	digit;

	digit = num / 10 + '0';
	write(1, &digit, 1);
	digit = num % 10 + '0';
	write(1, &digit, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = -1;
	while (first++ < 98)
	{
		second = first;
		while (second++ < 99)
		{
			print_num(first);
			write (1, " ", 1);
			print_num(second);
			if (first != 98)
			{
				write (1, ", ", 2);
			}
		}
	}
}
