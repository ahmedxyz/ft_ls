/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:51:30 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:16:00 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ws(va_list arg, t_format *format)
{
	wchar_t		*str;
	int			precision;

	if (!(str = (wchar_t*)va_arg(arg, wchar_t*)))
		str = L"(null)";
	precision = format->precision;
	if (precision < 0 || (int)ft_wstrlen(str) < precision)
		precision = ft_wstrlen(str);
	return (print_with_padding_nwstr(format, str, precision));
}
