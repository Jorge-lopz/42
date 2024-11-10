/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:17:35 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/19 20:21:40 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;
	char	*big_copy;
	char	*little_copy;

	big_copy = (char *)big;
	little_copy = (char *)little;
	len_little = ft_strlen(little_copy);
	i = 0;
	if (len_little == 0)
		return (big_copy);
	while (big_copy[i] && i < len)
	{
		j = 0;
		while (big_copy[i + j] == little_copy[j] && i + j < len
			&& j < len_little)
		{
			j++;
		}
		if (j == len_little)
			return (&big_copy[i]);
		i++;
	}
	return (0);
}
