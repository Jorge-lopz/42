/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:35:23 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/27 09:35:24 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	*range = NULL;
	if (min >= max)
		return (0);
	size = max - min;
	*range = (int *)malloc(size * 4);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*range;
	range = NULL;
	int res = ft_ultimate_range(&range, 5, 9);
	printf("%d\n", res);
	return(0);
}
*/
