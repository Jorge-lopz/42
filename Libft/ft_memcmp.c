/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 00:47:32 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/18 00:47:32 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *dest, const void *str, int n)
{
	int				i;
	int				diff;
	unsigned char	*str_copy;
	unsigned char	*dest_copy;

	dest_copy = (unsigned char *)dest;
	str_copy = (unsigned char *)str;
	i = 0;
	diff = 0;
	if (n)
		while (n--)
		{
			if (*dest_copy != *str_copy)
				return (*dest_copy - *str_copy);
			dest_copy++;
			str_copy++;
		}
	return (0);
}
