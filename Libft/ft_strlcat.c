/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:06:55 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/22 12:06:55 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_l;
	size_t	dest_l;

	i = 0;
	src_l = ft_strlen(src);
	dest_l = ft_strlen(dest);
	j = dest_l;
	if (size <= dest_l)
		return (size + src_l);
	while (src[i] && (j < size - 1))
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest_l + src_l);
}
