/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 00:37:56 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/18 00:37:56 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_copy;
	unsigned char	*src_copy;

	if (!dest && !src)
		return (0);
	dest_copy = (unsigned char *)dest;
	src_copy = (unsigned char *)src;
	if (dest < src)
		while (n--)
			*dest_copy++ = *src_copy++;
	else
	{
		dest_copy += n;
		src_copy += n;
		while (n--)
			*--dest_copy = *--src_copy;
	}
	return (dest);
}
