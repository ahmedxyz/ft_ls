/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:09:33 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:29 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_sign(t_format *format, char *prefix, int is_negative)
{
	if (is_negative == 1)
		prefix = append(prefix, '-');
	else if (format->flag_plus == 1)
		prefix = append(prefix, '+');
	else if (format->flag_space == 1)
		prefix = append(prefix, ' ');
	return (prefix);
}

char	*add_prefix(t_format *format, char *prefix)
{
	if (format->flag_hash == 1)
	{
		if (format->conversion == 'o')
			prefix = append(prefix, '0');
		if (format->conversion == 'x' || format->conversion == 'p')
		{
			prefix = append(prefix, '0');
			prefix = append(prefix, 'x');
		}
		if (format->conversion == 'X')
		{
			prefix = append(prefix, '0');
			prefix = append(prefix, 'X');
		}
	}
	return (prefix);
}

char	*add_leading_zeros(t_format *format, char *str, int prefix_len)
{
	if (format->precision == 0 && ft_strequ("0", str) == 1)
		str = trim_first(str);
	else if ((int)ft_strlen(str) <= format->precision)
	{
		while ((int)ft_strlen(str) < format->precision)
			str = prepend(str, '0');
	}
	else if (format->flag_zero == 1)
	{
		while ((int)ft_strlen(str) < format->width - prefix_len)
			str = prepend(str, '0');
	}
	return (str);
}
