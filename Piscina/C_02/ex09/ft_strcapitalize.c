/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:20:19 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/13 14:20:20 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		next_cap;
	char	*start;

	start = str;
	next_cap = 1;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + 32;
		if (next_cap)
		{
			next_cap = 0;
			if (*str >= 'a' && *str <= 'z')
				*str = *str - 32;
		}
		if (!((*str >= '0' && *str <= '9')
				|| (*str >= 'A' && *str <= 'Z')
				|| (*str >= 'a' && *str <= 'z')))
		{
			next_cap = 1;
		}
		str++;
	}
	return (start);
}
