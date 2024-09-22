/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:23:22 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/17 19:23:22 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_copy;
	unsigned char	*src_copy;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	dest_copy = (unsigned char *)dest;
	src_copy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_copy[i] = src_copy[i];
		i++;
	}
	return (dest);
}
