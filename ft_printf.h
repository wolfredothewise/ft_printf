/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhedo-ga <vhedo-ga <vhedo-ga@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:00:04 by vhedo-ga          #+#    #+#             */
/*   Updated: 2025/11/28 09:19:30 by vhedo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		handle_int(va_list *list);
int		handle_unsigned(va_list *list);
int		handle_hex_lower(va_list *list);
int		handle_hex_upper(va_list *list);
int		handle_pointer(va_list *list);
int		handle_char(va_list *list);
int		handle_percent(void);
int		handle_string(va_list *list);

void	ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_put_unsigned_nbr(unsigned int n);
int		ft_puthex_lower(unsigned long n);
int		ft_puthex_upper(unsigned long n);
int		ft_putptr(void *p);

#endif
