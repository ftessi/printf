/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftessi <ftessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:11:49 by ftessi            #+#    #+#             */
/*   Updated: 2026/06/19 02:26:13 by ftessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_handle_conversion(char spec, va_list *ap);

int	ft_putnbr_recursive(long n);

int	ft_putunsgd_recursive(unsigned int n);

int	ft_puthex(unsigned long n, char *base);

int	ft_putptr(void *ptr);

#endif