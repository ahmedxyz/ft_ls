/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:02:07 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:25 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_specifier(va_list arg, t_format *format, char **input)
{
	if (format->conversion == 'd' || format->conversion == 'i')
		return (print_d(arg, format));
	else if (format->conversion == 'u')
		return (print_u(arg, format));
	else if (format->conversion == 'o')
		return (print_o(arg, format));
	else if (format->conversion == 'x' || format->conversion == 'X')
		return (print_x(arg, format));
	else if (format->conversion == 'p')
		return (print_p(arg, format));
	else if (format->conversion == 'c' && format->length == 'l')
		return (print_wc(arg, format));
	else if (format->conversion == 'c')
		return (print_c(arg, format));
	else if (format->conversion == 's' && format->length == 'l')
		return (print_ws(arg, format));
	else if (format->conversion == 's')
		return (print_s(arg, format));
	else if (format->conversion == '%')
		return (print_percent(format));
	else
		return (print_invalid(input));
}

int		parse_specifier(va_list arg, char **input)
{
	t_format	*format;
	int			chars_printed;

	format = (t_format*)malloc(sizeof(t_format));
	parse_flags(format, input);
	parse_width(arg, format, input);
	parse_precision(arg, format, input);
	parse_length(format, input);
	parse_conversion(format, input);
	chars_printed = print_specifier(arg, format, input);
	free(format);
	return (chars_printed);
}

int		parse_input(va_list arg, char **input)
{
	int		chars_printed;

	chars_printed = 0;
	while (**input != '\0')
	{
		if (**input == '%')
		{
			(*input)++;
			chars_printed += parse_specifier(arg, input);
		}
		else
		{
			ft_putchar(**input);
			chars_printed++;
			(*input)++;
		}
	}
	return (chars_printed);
}

int		ft_printf(const char *input, ...)
{
	va_list	arg;
	int		chars_printed;

	va_start(arg, input);
	chars_printed = parse_input(arg, (char**)&input);
	va_end(arg);
	return (chars_printed);
}
