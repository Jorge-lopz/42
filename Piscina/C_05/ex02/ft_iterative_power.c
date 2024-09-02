/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:36 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/21 13:42:36 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	res = nb;
	while (power > 1)
	{
		res = res * nb;
		power--;
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_power(5, 3));
}
*/
