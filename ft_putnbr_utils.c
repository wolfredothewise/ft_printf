/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:25:58 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/11/24 18:39:53 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_put_unsigned_nbr(unsigned int n)
{
	int	j;

	j = 0;
	if (n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
		j++;
	}
	else
	{
		j = j + ft_put_unsigned_nbr((n / 10));
		j = j + ft_put_unsigned_nbr((n % 10));
	}
	return (j);
}

int	ft_putptr(void *p)
{
	int				j;
	unsigned long	addres;

	if (p == NULL)
	{
		return (ft_putstr("(nil)"));
	}
	addres = (unsigned long)p;
	write(1, "0x", 2);
	j = ft_puthex_lower(addres);
	return (j + 2);
}

int	ft_puthex_lower(unsigned long n)
{
	unsigned long	size;
	int				j;
	char			*base;

	base = "0123456789abcdef";
	size = 16;
	j = 0;
	if (n == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	if (n >= size)
	{
		j = j + ft_puthex_lower(n / size);
	}
	ft_putchar(base[n % size]);
	j++;
	return (j);
}

int	ft_puthex_upper(unsigned long n)
{
	unsigned long	size;
	int				j;
	char			*base;

	base = "0123456789ABCDEF";
	size = 16;
	j = 0;
	if (n == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	if (n >= size)
	{
		j = j + ft_puthex_upper(n / size);
	}
	ft_putchar(base[n % size]);
	j++;
	return (j);
}
