/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:01 by jorlopez          #+#    #+#             */
/*   Updated: 2024/11/10 14:31:58 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	unsigned long long	ptr_long;
	int					count;

	count = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count += ft_putstr("0x");
	ptr_long = (unsigned long long)ptr;
	count += ft_base16(ptr_long, "0123456789abcdef");
	return (count);
}

int	ft_printhex(unsigned int nb, int type)
{
	char	*alpha;

	if (type == 'x')
		alpha = "0123456789abcdef";
	else
		alpha = "0123456789ABCDEF";
	return (ft_base16(nb, alpha));
}

int	ft_base16(unsigned long nb, char *alpha)
{
	int	count;

	count = 0;
	if (nb > 15)
	{
		count += ft_base16(nb / 16, alpha);
		count += ft_base16(nb % 16, alpha);
	}
	else
		count += ft_putchr(alpha[nb]);
	if (count < 0)
		return (-1);
	return (count);
}
