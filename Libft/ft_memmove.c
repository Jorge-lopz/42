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

void	*ft_memmove(void *dest, const void *src, int n)
{
	unsigned const char	*src_copy;
	unsigned char		*dest_copy;
	unsigned int		i;

	src_copy = (unsigned const char *) src;
	dest_copy = (unsigned char *) dest;
	i = 0;
	while (src_copy[i] != '\0' && i < n)
	{
		dest_copy[i] = src_copy[i];
		i++;
	}
	while (i < n)
	{
		dest_copy[i] = '\0';
		i++;
	}
	return (dest);
}
