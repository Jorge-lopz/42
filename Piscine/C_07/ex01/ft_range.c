/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:28:02 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/27 08:28:03 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	*range_copy;

	range = NULL;
	if (min >= max)
		return (NULL);
	range = (int *)malloc((max - min) * sizeof(int));
	range_copy = range;
	if (range == NULL)
		return (NULL);
	while (min < max)
	{
		*range = min;
		range++;
		min++;
	}
	return (range_copy);
}
/*
#include <stdio.h>

int	main(void)
{
	int *res = ft_range(9, 5);
	int i = 0;
	
	(void) res;
	(void) i;
	while (i < 4)
	{
		printf("%d\n", res[i]);
		i++;
	}
	//free(res);
	return(0);
}
*/
