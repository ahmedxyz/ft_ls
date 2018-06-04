/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:58:52 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:46 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_x(va_list arg, t_format *format)
{
	uintmax_t	num;
	char		*prefix;
	char		*str;

	num = cast_length_unsigned(arg, format);
	prefix = (num != 0) ? add_prefix(format, ft_strnew(0)) : ft_strnew(0);
	str = ft_uitoa_base(num, 16);
	str = (format->conversion == 'X') ? ft_strtoupper(str) : str;
	str = add_leading_zeros(format, str, ft_strlen(prefix));
	str = ft_strjoin_wrapper(prefix, str);
	return (print_with_padding_nstr_wrapper(format, str));
}
