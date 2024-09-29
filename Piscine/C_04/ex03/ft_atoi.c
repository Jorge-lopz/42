/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:38:11 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/19 13:38:13 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("\n +123"));  // Debería imprimir 123
	printf("%d\n", ft_atoi(" ---+--+1234ab567"));  // Debería imprimir -1234
		printf("%d\n", ft_atoi(" 1234-567"));  // Debería imprimir 1234
    	printf("%d\n", ft_atoi("   +42"));             // Debería imprimir 42
    	printf("%d\n", ft_atoi("   -+--123"));         // Debería imprimir -123
    	printf("%d\n", ft_atoi("   +++++123"));        // Debería imprimir 123
    	printf("%d\n", ft_atoi("   ---+--++--+123"));   // Debería imprimir -123
}
*/
