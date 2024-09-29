/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:57:55 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/15 19:57:56 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_getlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_getlen(to_find);
	if (len == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (j == len)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
