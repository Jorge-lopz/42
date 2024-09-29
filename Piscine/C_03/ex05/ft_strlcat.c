/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:16:59 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/16 13:17:00 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_getlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_l;
	unsigned int	dest_l;

	i = 0;
	src_l = ft_getlen(src);
	dest_l = ft_getlen(dest);
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
