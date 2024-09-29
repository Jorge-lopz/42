/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:14:12 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/28 18:14:39 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	open_file(char *path)
{
	int	file_id;

	file_id = open(path, O_RDONLY);
	if (file_id == -1)
		write(1, "ERROR: Couldn't open file", 26);
	return (file_id);
}

int	close_file(int file_id)
{
	if (close(file_id) == -1)
	{
		write(1, "ERROR: Couldn't close file", 27);
		return (-1);
	}
	return (0);
}

char	*get_text(char *path)
{
	char	buff[1];
	char	*text;
	int		file_id;
	int		bytes_read;

	bytes_read = 0;
	file_id = open_file(path);
	if (file_id == -1)
		return (NULL);
	while (read(file_id, buff, 1) == 1)
		bytes_read++;
	if (close_file(file_id) == -1)
		return (NULL);
	file_id = open_file(path);
	if (file_id == -1)
		return (NULL);
	text = (char *)malloc(bytes_read * sizeof(char));
	if (text == NULL)
		write(1, "ERROR: Failed memory allocation", 32);
	read(file_id, text, bytes_read);
	if (close_file(file_id) == -1)
		return (NULL);
	return (text);
}

char	*console_input(int *rows, int *cols)
{
	char	buff[1024];
	char	*text;
	int		size;
	int		i;
	int		j;

	size = read(0, buff, 1023);
	buff[size] = '\0';
	i = 0;
	j = 0;
	text = (char *)malloc(size);
	while (buff[i])
		text[j++] = buff[i++];
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	*rows = get_rows(i, text);
	if (*rows == -1)
		return (NULL);
	if (get_legend(text, *rows) == -1)
		return (NULL);
	*cols = ((get_len(text) - (i + 1)) / *rows) - 1;
	if (generate_map(*rows, *cols, i++, text) == -1)
		return (NULL);
	return (text);
}

int	get_legend(char *text, int rows)
{
	int	i;

	i = 0;
	while (*text && *text != '\n')
	{
		if (*text < 32 || *text > 126)
			return (-1);
		text++;
		i++;
	}
	if (i < 4)
		return (-1);
	text--;
	g_result = *text;
	text--;
	g_obstacle = *text;
	text--;
	g_normal = *text;
	i -= 3;
	if (check_equal_rows(i, &text, rows) == -1 || check_dup_leyend() == -1)
		return (-1);
	return (0);
}
