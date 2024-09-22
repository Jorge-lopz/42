/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 00:45:18 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/18 00:45:18 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_copy;
	unsigned char	c_copy;

	s_copy = (unsigned char *)s;
	c_copy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_copy[i] == c_copy)
			return ((void *)&s_copy[i]);
		i++;
	}
	return (NULL);
}
