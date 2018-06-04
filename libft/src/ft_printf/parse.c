/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 01:37:02 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:31 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_format *format, char **input)
{
	format->flag_hash = 0;
	format->flag_zero = 0;
	format->flag_minus = 0;
	format->flag_plus = 0;
	format->flag_space = 0;
	while (ft_strchr("#0-+ ", **input) != NULL)
	{
		if (**input == '#')
			format->flag_hash = 1;
		if (**input == '0')
			format->flag_zero = 1;
		if (**input == '-')
			format->flag_minus = 1;
		if (**input == '+')
			format->flag_plus = 1;
		if (**input == ' ')
			format->flag_space = 1;
		(*input)++;
	}
	if (format->flag_minus == 1 && format->flag_zero == 1)
		format->flag_zero = 0;
	if (format->flag_plus == 1 && format->flag_space == 1)
		format->flag_space = 0;
}

void	parse_width(va_list arg, t_format *format, char **input)
{
	format->width = 0;
	while (ft_isdigit(**input) != 0)
	{
		format->width *= 10;
		format->width += **input - '0';
		(*input)++;
	}
	if (**input == '*')
	{
		format->width = va_arg(arg, int);
		if (format->width < 0)
		{
			format->width *= -1;
			format->flag_minus = 1;
		}
		(*input)++;
	}
}

void	parse_precision(va_list arg, t_format *format, char **input)
{
	format->precision = -1;
	if (**input == '.')
	{
		format->precision = 0;
		(*input)++;
		while (ft_isdigit(**input) != 0)
		{
			format->precision *= 10;
			format->precision += **input - '0';
			(*input)++;
		}
		if (**input == '*')
		{
			format->precision = va_arg(arg, int);
			(*input)++;
		}
	}
}

void	parse_length(t_format *format, char **input)
{
	format->length = 0;
	if (ft_strchr("hl", **input) != NULL)
	{
		format->length = **input;
		(*input)++;
		if (ft_strchr("hl", **input) != NULL)
		{
			format->length = ft_toupper(format->length);
			(*input)++;
		}
	}
	else if (ft_strchr("jz", **input) != NULL)
	{
		format->length = **input;
		(*input)++;
	}
}

void	parse_conversion(t_format *format, char **input)
{
	format->conversion = 0;
	if (ft_strchr("dDiuUoOxXpcCsS%", **input) != NULL)
	{
		format->conversion = **input;
		(*input)++;
	}
	if (ft_strchr("DUOCS", format->conversion) != NULL)
	{
		format->conversion = ft_tolower(format->conversion);
		format->length = 'l';
	}
	if (format->conversion == 'p')
		format->flag_hash = 1;
}
