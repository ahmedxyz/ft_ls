/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:51:15 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:57 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_wc(va_list arg, t_format *format)
{
	wchar_t	c;

	c = va_arg(arg, wint_t);
	return (print_with_padding_wchar(format, c));
}
