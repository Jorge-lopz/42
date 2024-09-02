/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:19:01 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/25 21:19:02 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char	*g_file_content;

int	getlen(char *str);

void	putstr(char *str);

int	open_file(char *path);

char	*read_file(int file_id);

int	close_file(int file_id);

void	*create_malloc(int bytes);

int	is_valid_line(int i);
