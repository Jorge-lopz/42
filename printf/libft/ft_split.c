/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:12:00 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/28 21:12:00 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

size_t	ft_get_word_len(char const *s, char c)
{
	if (ft_strchr(s, c))
		return (ft_strchr(s, c) - s);
	return (ft_strlen(s));
}

static void	ft_freelist(char **lst, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;
	int		word_count;

	word_count = ft_countword(s, c);
	lst = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!s || !lst)
		return (NULL);
	i = 0;
	while (*s && i < word_count)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_len = ft_get_word_len(s, c);
			lst[i] = ft_substr(s, 0, word_len);
			if (!lst[i++])
				return (ft_freelist(lst, i--), NULL);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}
