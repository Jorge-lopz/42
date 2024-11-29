/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:43:30 by jorlopez          #+#    #+#             */
/*   Updated: 2024/11/29 10:43:30 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>

char	*get_next_line(int fd);

char	*ft_strdup(const char *str);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
