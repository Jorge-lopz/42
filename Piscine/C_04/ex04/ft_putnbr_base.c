/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:31:33 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/20 12:31:34 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	valid_base(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len])
	{
		i = len + 1;
		while (base[i])
		{
			if (base[i] == base[len] || base[len] == '+'
				|| base[len] == '-')
				return (0);
			i++;
		}
		len++;
	}
	if (len < 2)
		return (0);
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = valid_base(base);
	if (!len)
		return ;
	if (nbr <= -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base((-(long int)nbr) / len, base);
		ft_putnbr_base((-(long int)nbr) % len, base);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= len)
		ft_putnbr_base(nbr / len, base);
	write(1, &base[nbr % len], 1);
}
/*
int	main(void)
{
	ft_putnbr_base(0, "01");
}
*/
