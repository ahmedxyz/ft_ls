/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:16:15 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:42 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_u(va_list arg, t_format *format)
{
	uintmax_t	num;
	char		*str;

	num = cast_length_unsigned(arg, format);
	str = ft_uitoa_base(num, 10);
	str = add_leading_zeros(format, str, 0);
	return (print_with_padding_nstr_wrapper(format, str));
}
