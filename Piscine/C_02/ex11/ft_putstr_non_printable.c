/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:43:28 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/13 16:43:29 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex[16];

	i = -1;
	while (++i < 10)
	{
		hex[i] = '0' + i;
	}
	while (i < 16)
	{
		hex[i] = 'a' + (i - 10);
		i++;	
	}
	while (*str)
	{
		if (*str >= 32 && *str < 127)
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hex[*str / 16], 1);
			write(1, &hex[*str % 16], 1);
		}
		str++;
	}
}

int	main(void)
{
	ft_putstr_non_printable("H\nla");
}
