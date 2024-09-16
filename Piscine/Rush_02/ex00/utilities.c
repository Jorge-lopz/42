/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:19:11 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/25 21:19:12 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush.h"

#include <stdio.h>

void	*create_malloc(int bytes)
{
	void *pointer;
	
	pointer = malloc(bytes);
	if (pointer == NULL)
        	putstr("ERROR: Memory allocation failed\n");
    	return (pointer);
}

int	getlen(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	putstr(char *str)
{
	while (*str != '\0')
	{
		write (1, str, 1);
		str++;
	}
}

int	num_compare(char *num, char *comp)
{
	int	num_len;
	int	comp_len;
	
	num_len = getlen(num);
	comp_len = getlen(comp);
	if (num_len > comp_len)
		return (1);
	else if (num_len == comp_len)
	{
	
	
	}
	return (0);
}
