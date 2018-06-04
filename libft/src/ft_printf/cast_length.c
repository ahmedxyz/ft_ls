/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 00:17:01 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:33 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	cast_length_signed(va_list arg, t_format *format)
{
	if (format->length == 'H')
		return ((char)va_arg(arg, int));
	else if (format->length == 'h')
		return ((short)va_arg(arg, int));
	else if (format->length == 'l')
		return ((long)va_arg(arg, long));
	else if (format->length == 'L')
		return ((long long)va_arg(arg, long));
	else if (format->length == 'j')
		return ((intmax_t)va_arg(arg, intmax_t));
	else if (format->length == 'z')
		return ((ssize_t)va_arg(arg, ssize_t));
	else
		return ((int)va_arg(arg, int));
}

intmax_t	cast_length_unsigned(va_list arg, t_format *format)
{
	if (format->length == 'H')
		return ((unsigned char)va_arg(arg, unsigned int));
	else if (format->length == 'h')
		return ((unsigned short)va_arg(arg, unsigned int));
	else if (format->length == 'l')
		return ((unsigned long)va_arg(arg, unsigned long));
	else if (format->length == 'L')
		return ((unsigned long long)va_arg(arg, unsigned long));
	else if (format->length == 'j')
		return ((uintmax_t)va_arg(arg, uintmax_t));
	else if (format->length == 'z')
		return ((size_t)va_arg(arg, size_t));
	else
		return ((unsigned int)va_arg(arg, unsigned int));
}
