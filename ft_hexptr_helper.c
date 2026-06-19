/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexptr_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftessi <ftessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 01:08:29 by ftessi            #+#    #+#             */
/*   Updated: 2026/06/19 02:31:39 by ftessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, base);
	}
	write(1, &base[n % 16], 1);
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = write(1, "0x", 2);
	count += ft_puthex((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
