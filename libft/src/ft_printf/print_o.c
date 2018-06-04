/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:57:54 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:44 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_o(va_list arg, t_format *format)
{
	uintmax_t	num;
	char		*prefix;
	char		*str;

	num = cast_length_unsigned(arg, format);
	prefix = ft_strnew(0);
	if (num != 0 || format->precision == 0)
		prefix = add_prefix(format, prefix);
	str = ft_uitoa_base(num, 8);
	str = add_leading_zeros(format, str, ft_strlen(prefix));
	str = ft_strjoin_wrapper(prefix, str);
	return (print_with_padding_nstr_wrapper(format, str));
}
