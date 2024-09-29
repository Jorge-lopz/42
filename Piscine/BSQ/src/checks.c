/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:14:05 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/28 18:14:07 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_equal_rows(int i, char **text, int rows)
{
	int	res;
	int	j;

	j = 1;
	res = 0;
	while (i > 0)
	{
		(*text)--;
		res += ((**text - '0') * j);
		j *= 10;
		i--;
	}
	if (res != rows)
		return (-1);
	return (0);
}

int	check_dup_leyend(void)
{
	if (g_normal == g_obstacle || g_normal == g_result
		|| g_result == g_obstacle)
		return (-1);
	return (0);
}

int	check_valid_char(char chr)
{
	if (chr != g_normal && chr != g_obstacle && chr != '\n' && chr != '\0')
		return (-1);
	return (0);
}

void	frees(char *text, int rows)
{
	int	i;

	free(text);
	i = 0;
	while (i < rows)
	{
		free(g_res_map[i]);
		i++;
	}
	free(g_res_map);
}
