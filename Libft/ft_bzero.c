/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:21:12 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/17 19:21:12 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*str_copy;

	str_copy = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		str_copy[i] = 0;
		i++;
	}
}
