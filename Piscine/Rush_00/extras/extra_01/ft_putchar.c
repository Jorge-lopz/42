/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorita- <lzorita-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:28:46 by lzorita-          #+#    #+#             */
/*   Updated: 2024/08/11 20:28:53 by lzorita-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>                  

void	ft_putchar(char c)
{
	write(1, &c, 1);
}