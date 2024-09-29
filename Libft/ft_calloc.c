/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:07:33 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/26 09:07:33 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if (nmemb != 0 && size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (0);
	while (i < nmemb * size)
		((unsigned char *)str)[i++] = 0;
	return (str);
}
