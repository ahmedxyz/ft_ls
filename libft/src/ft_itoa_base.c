/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 10:28:24 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/15 15:43:40 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(intmax_t n, int base)
{
	int		digits;
	char	*new;
	char	*symbols;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	digits = ft_digits_base(n, base);
	if (!(new = ft_strnew(digits)))
		return (NULL);
	new[digits] = '\0';
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		new[0] = '-';
		n = -n;
	}
	if (n == 0)
		new[0] = '0';
	while (n)
	{
		digits--;
		new[digits] = symbols[n % base];
		n /= base;
	}
	return (new);
}
