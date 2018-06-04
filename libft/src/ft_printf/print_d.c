/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:06:04 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:39 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_d(va_list arg, t_format *format)
{
	intmax_t	num;
	char		*prefix;
	char		*str;

	num = cast_length_signed(arg, format);
	prefix = add_sign(format, ft_strnew(0), (num < 0) ? 1 : 0);
	str = ft_itoa_base(num, 10);
	str = (num < 0) ? trim_first(str) : str;
	str = add_leading_zeros(format, str, ft_strlen(prefix));
	str = ft_strjoin_wrapper(prefix, str);
	return (print_with_padding_nstr_wrapper(format, str));
}
