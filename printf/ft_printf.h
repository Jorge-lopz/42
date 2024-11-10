/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:24:29 by jorlopez          #+#    #+#             */
/*   Updated: 2024/11/08 14:24:29 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchr(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);
int	ft_printhex(unsigned int nb, int type);
int	ft_printptr(void *arg);
int	ft_base16(unsigned long nb, char *alpha);
