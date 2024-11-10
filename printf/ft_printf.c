/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:31:25 by jorlopez          #+#    #+#             */
/*   Updated: 2024/11/10 14:31:25 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += (char)ft_putchr(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (type == 'p')
		count += ft_printptr(va_arg(args, void *));
	else if (type == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int));
	else if (type == 'X' || type == 'x')
		count += (char)ft_printhex(va_arg(args, int), type);
	else if (type == '%')
		return (write(1, "%", 1));
	return (count);
}

int	ft_printf(const char *string, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			count += ft_type(*string, args);
		}
		else
			count += ft_putchr(*string);
		string++;
	}
	va_end(args);
	if (count < 0)
		return (-1);
	return (count);
}
