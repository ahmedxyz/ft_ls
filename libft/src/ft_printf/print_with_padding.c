/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_padding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:15:37 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:36 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_with_padding_nstr(t_format *format, char *str, int n)
{
	int		padding;

	padding = ft_max(format->width - n, 0);
	if (format->flag_minus == 0)
		ft_putnchar(' ', padding);
	ft_putnstr(str, n);
	if (format->flag_minus == 1)
		ft_putnchar(' ', padding);
	return (n + padding);
}

int		print_with_padding_nstr_wrapper(t_format *format, char *str)
{
	int		chars_printed;

	chars_printed = print_with_padding_nstr(format, str, ft_strlen(str));
	free(str);
	return (chars_printed);
}

int		print_with_padding_nwstr(t_format *format, wchar_t *str, int n)
{
	int		padding;

	padding = ft_max(format->width - n, 0);
	if (format->flag_minus == 0)
		ft_putnchar(' ', padding);
	ft_putnwstr(str, n);
	if (format->flag_minus == 1)
		ft_putnchar(' ', padding);
	return (n + padding);
}

int		print_with_padding_char(t_format *format, char c)
{
	int		padding;

	padding = ft_max(format->width - 1, 0);
	if (format->flag_minus == 0)
		ft_putnchar(' ', padding);
	ft_putchar(c);
	if (format->flag_minus == 1)
		ft_putnchar(' ', padding);
	return (1 + padding);
}

int		print_with_padding_wchar(t_format *format, wchar_t c)
{
	int		padding;

	padding = ft_max(format->width - ft_wcharlen(c), 0);
	if (format->flag_minus == 0)
		ft_putnchar(' ', padding);
	ft_putwchar(c);
	if (format->flag_minus == 1)
		ft_putnchar(' ', padding);
	return (ft_wcharlen(c) + padding);
}
