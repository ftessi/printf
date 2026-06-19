/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftessi <ftessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:29:45 by ftessi            #+#    #+#             */
/*   Updated: 2026/06/19 02:32:50 by ftessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_handle_conversion(format[i], &ap);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

int	ft_handle_conversion(char spec, va_list *ap)
{
	if (spec == 'c')
		return (ft_putchar((char)va_arg(*ap, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (spec == 'd')
		return (ft_putnbr_recursive(va_arg(*ap, long)));
	else if (spec == 'i')
		return (ft_putnbr_recursive(va_arg(*ap, long)));
	else if (spec == 'u')
		return (ft_putunsgd_recursive(va_arg(*ap, unsigned int)));
	else if (spec == 'x')
		return (ft_puthex(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (spec == 'X')
		return (ft_puthex(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (spec == 'p')
		return (ft_putptr(va_arg(*ap, void *)));
	else if (spec == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
