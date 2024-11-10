/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:33:50 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/26 09:33:50 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	res = (char *)malloc((i + 1) * 1);
	if (res == NULL)
		return (0);
	while (str[j])
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
