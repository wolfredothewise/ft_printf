/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:50:15 by vhedo-ga          #+#    #+#             */
/*   Updated: 2026/02/03 14:50:58 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

int	handle_char(va_list *list)
{
	char	c;

	c = (char)va_arg(*list, int);
	write(1, &c, 1);
	return (1);
}

int	handle_string(va_list *list)
{
	char	*str;

	str = va_arg(*list, char *);
	return (ft_putstr(str));
}

int	handle_percent(void)
{
	char	porc;

	porc = '%';
	write(1, &porc, 1);
	return (1);
}

int	which_type(char type, va_list *list)
{
	if (type == 'c')
		return (handle_char(list));
	if (type == '%')
		return (handle_percent());
	if (type == 's')
		return (handle_string(list));
	if (type == 'd' || type == 'i')
		return (handle_int(list));
	if (type == 'u')
		return (handle_unsigned(list));
	if (type == 'x')
		return (handle_hex_lower(list));
	if (type == 'X')
		return (handle_hex_upper(list));
	if (type == 'p')
		return (handle_pointer(list));
	return (0);
}

int	ft_printf(const char *text, ...)
{
	va_list	list;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(list, text);
	while (text[i])
	{
		while (text[i] && text[i] != '%')
		{
			write(1, &text[i], 1);
			j++;
			i++;
		}
		if (text[i] == '%')
		{
			i++;
			j = j + which_type(text[i], &list);
			i++;
		}
	}
	va_end(list);
	return (j);
}
