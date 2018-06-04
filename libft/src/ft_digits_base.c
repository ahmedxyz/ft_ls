/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 10:22:25 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/03 21:32:12 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digits_base(intmax_t n, int base)
{
	int		digits;

	digits = 0;
	if (n < 0)
		digits++;
	if (n == 0)
		digits++;
	while (n)
	{
		digits++;
		n /= base;
	}
	return (digits);
}
