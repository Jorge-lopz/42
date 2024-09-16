/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:58:56 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/27 09:59:00 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*return_null(void)
{
	char	*res;

	res = (char *)malloc(1);
	if (res != NULL)
		res[0] = '\0';
	return (res);
}

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	get_total_size(int size, char **strs, char *sep)
{
	int	total_size;
	int	i;

	i = 0;
	total_size = 0;
	while (i < size)
	{
		total_size += get_len(strs[i]);
		if (i < size - 1)
			total_size += get_len(sep);
		i++;
	}
	return (total_size);
}

void	str_copy(char *dest, char *src, int *k)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[*k] = src[j];
		(*k)++;
		j++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		total_size;
	int		i;
	int		k;

	if (size <= 0)
		return (return_null());
	total_size = get_total_size(size, strs, sep);
	res = (char *)malloc((total_size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		str_copy(res, strs[i], &k);
		if (i < size - 1)
			str_copy(res, sep, &k);
		i++;
	}
	res[k] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char *strs[] = {"Hello", "Hola", "Soy", "Jorge"};
	char *sep = "--";
	char *res;
	
	res = ft_strjoin(4, strs, sep);
	if (res)
	{
		printf("%s", res);
		free(res);
	}
	return (0);
}
*/
