/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr(recursive).c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:53:59 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/08 11:35:13 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  Create a function that displays the number entered as a parameter. The function
  has to be able to display all possible values within an int type variable.
*/

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	num;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	num = (nb % 10) + '0';
	write(1, &num, 1);
}
