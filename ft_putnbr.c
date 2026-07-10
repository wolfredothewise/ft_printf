/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:46:50 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/11/24 14:57:24 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_min(void)
{
	write(1, "-2147483648", 11);
	return (11);
}

int	ft_putnbr(int n)
{
	int	j;

	j = 0;
	if (n == -2147483648)
		return (ft_handle_min());
	if (n < 0)
	{
		write(1, "-", 1);
		j++;
		n = -1 * n;
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
		j++;
	}
	else
	{
		j = j + ft_putnbr((n / 10));
		j = j + ft_putnbr((n % 10));
	}
	return (j);
}
