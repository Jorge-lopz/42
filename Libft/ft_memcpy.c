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

void	*ft_memcpy(void *dest, const void *src, int n)
{
	unsigned char	*dest_copy;
	unsigned char	*src_copy;
	int				i;

	dest_copy = (unsigned char *)dest;
	src_copy = (unsigned char *)src;
	if (dest_copy == src || !n)
		return (dest);
	i = 0;
	while (n > i)
	{
		dest_copy[i] = src_copy[i];
		i++;
	}
	return (dest);
}
