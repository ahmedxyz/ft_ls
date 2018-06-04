/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:58:08 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/04 16:33:23 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(uintmax_t n, int base)
{
	int		digits;
	char	*new;
	char	*symbols;

	if (base < 2 || 16 < base)
		return (NULL);
	digits = ft_udigits_base(n, base);
	if (!(new = ft_strnew(digits)))
		return (NULL);
	new[digits] = '\0';
	symbols = "0123456789abcdef";
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
