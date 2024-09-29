/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:28:58 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/23 13:28:59 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	res = (char *)malloc((i + 1) * 1);
	if (res == NULL)
		return (NULL);
	while (src[j])
	{
		res[j] = src[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char *res = ft_strdup("");
	printf("%s", res);
	free(res);
	return(0);
}
*/
