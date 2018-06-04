/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 01:12:37 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:16:02 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_invalid(char **input)
{
	char	*limit;
	int		chars_printed;

	limit = *input;
	chars_printed = 0;
	while (**input != '\0' && **input != '%')
		(*input)--;
	while (*input < limit)
	{
		ft_putchar(**input);
		chars_printed++;
		(*input)++;
	}
	return (chars_printed);
}
