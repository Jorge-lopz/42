/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:13:21 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/07 19:10:23 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
  Create a function that displays all different combinations of three different 
  digits in ascending order, listed by ascending order (Repetition is voluntary).
  TEST: ./a.out | cat -e => 012, 013, 014, 015, 016, 017, 018, 019, ..., 789$
*/

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				write(1, &i, 1);
				write(1, &j, 1);
				write(1, &k, 1);
				if (i < '7')
					write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
}
