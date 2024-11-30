/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:38:55 by jorlopez          #+#    #+#             */
/*   Updated: 2024/11/30 13:37:01 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*temp;
	char	*temp_buffer;
	int		bytes_read;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	// Start reading from file
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	// Read until newline is found or EOF
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0) // Error in read
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[bytes_read] = '\0'; // Null-terminate the string
		temp_buffer = buffer;
		buffer = ft_strjoin(buffer, temp); // Append the newly read content
		free(temp_buffer);
		// Free the old buffer to prevent memory leaks
		if (!buffer)
		{
			free(temp);
			return (NULL); // Handle memory allocation failure
		}
	}
	free(temp); // Always free temporary buffer
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		len;

	if (!buffer || !*buffer) // Prevent processing empty or NULL buffer
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n') // Find the length up to newline
		len++;
	if (buffer[len] == '\n') // Include newline in the extracted line
		len++;
	line = ft_substr(buffer, 0, len); // Extract the line
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	int		start;

	if (!buffer || !*buffer) // If buffer is empty or NULL,
	{
		free(buffer);
		return (NULL); // Return NULL and free buffer
	}
	start = 0;
	while (buffer[start] && buffer[start] != '\n')
		// Skip over the content until newline
		start++;
	if (buffer[start] == '\n') // Skip past newline as well
		start++;
	new_buffer = ft_strdup(buffer + start);
	// Create a new buffer from the remaining content
	free(buffer);        // Free the old buffer
	return (new_buffer); // Return the updated buffer
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1) // Invalid file descriptor or buffer size
		return (NULL);
	// Initialize buffer if it's NULL
	if (!buffer)
		buffer = ft_strdup(""); // Empty buffer initialization
	// Read the file into buffer until newline is found or EOF
	buffer = read_to_buffer(fd, buffer);
	if (!buffer) // If there was an error reading or buffer is NULL, return NULL
		return (NULL);
	// If buffer is empty (EOF or nothing to read), clean up and return NULL
	if (!*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	// Extract the line from the buffer
	line = extract_line(buffer);
	buffer = update_buffer(buffer);
	// Update the buffer to remove the extracted line
	return (line); // Return the extracted line
}
