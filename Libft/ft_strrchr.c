/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:12:22 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/19 20:16:23 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = 0;
	while (*s)
	{
		if (*s == (char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last_occurrence);
}
