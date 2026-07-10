/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:20:35 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/11/24 17:01:21 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	handle_int(va_list *list)
{
	int	n;

	n = va_arg(*list, int);
	return (ft_putnbr(n));
}

int	handle_unsigned(va_list *list)
{
	unsigned int	n;

	n = va_arg(*list, unsigned int);
	return (ft_put_unsigned_nbr(n));
}

int	handle_hex_lower(va_list *list)
{
	unsigned int	n;

	n = va_arg(*list, unsigned int);
	return (ft_puthex_lower(n));
}

int	handle_hex_upper(va_list *list)
{
	unsigned int	n;

	n = va_arg(*list, unsigned int);
	return (ft_puthex_upper(n));
}

int	handle_pointer(va_list *list)
{
	void	*p;

	p = va_arg(*list, void *);
	return (ft_putptr(p));
}
