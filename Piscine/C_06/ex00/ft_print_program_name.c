/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:39:54 by jorlopez          #+#    #+#             */
/*   Updated: 2024/08/21 19:39:54 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc < 1)
		return (1);
	while (*argv[0])
	{
		write(1, argv[0], 1);
		argv[0]++;
	}
	write (1, "\n", 1);
	return (0);
}
