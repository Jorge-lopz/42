/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 00:47:32 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/19 20:04:08 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dest, const void *str, size_t n)
{
	size_t			i;
	unsigned char	*dest_copy;
	unsigned char	*str_copy;

	dest_copy = (unsigned char *)dest;
	str_copy = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (dest_copy[i] != str_copy[i])
			return (dest_copy[i] - str_copy[i]);
		i++;
	}
	return (0);
}
