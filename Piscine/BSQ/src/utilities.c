/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:14:53 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/28 18:14:56 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	generate_map(int rows, int cols, int start, char *text)
{
	int	i;
	int	j;
	int	normal_nmb;

	normal_nmb = 0;
	if (allocate_map_memory(rows, cols) == -1)
		return (-1);
	i = -1;
	while (i++ < rows - 1)
	{
		j = -1;
		while (j++ < cols - 1)
		{
			if (text[++start] == '\n')
				start++;
			if (text[start] == g_normal)
				normal_nmb++;
			if (check_valid_char(text[start]) == -1)
				return (-1);
			g_map[i][j] = text[start];
		}
	}
	if (normal_nmb == 0)
		return (-1);
	return (0);
}

int	get_rows(int i, char *text)
{
	int	rows;
	int	past_len;
	int	len;

	rows = -1;
	past_len = -1;
	len = 0;
	while (text[i])
	{
		len++;
		if (text[i] == '\n')
		{
			if (rows > 0 && past_len != -1 && len != past_len)
				return (-1);
			past_len = len;
			len = 0;
			rows++;
		}
		i++;
	}
	return (rows);
}

int	get_len(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	get_min_around(int i, int j)
{
	int	min;

	min = g_res_map[i - 1][j - 1];
	if (g_res_map[i][j - 1] < min)
		min = g_res_map[i][j - 1];
	if (g_res_map[i - 1][j] < min)
		min = g_res_map[i - 1][j];
	return (min);
}

int	allocate_map_memory(int rows, int cols)
{
	int	i;

	g_map = (char **)malloc(rows * sizeof(char *));
	if (g_map == NULL)
	{
		write(1, "Memory allocation failed.", 26);
		return (-1);
	}
	i = -1;
	while (i++ < rows)
	{
		g_map[i] = (char *)malloc(cols * sizeof(char));
		if (g_map[i] == NULL)
		{
			write(1, "Memory allocation failed.", 26);
			return (-1);
		}
	}
	return (0);
}
