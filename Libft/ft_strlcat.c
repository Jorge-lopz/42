/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 00:42:44 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/18 00:42:44 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_l;
	unsigned int	dest_l;

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
