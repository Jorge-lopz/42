/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:03:23 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/29 11:03:23 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		tmp;

	len = (n <= 0);
	tmp = n;
	while (tmp && ++len)
		tmp /= 10;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n < 0)
			str[--len] = -(n % 10) + '0';
		else
			str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
