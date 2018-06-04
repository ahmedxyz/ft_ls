/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udigits_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:00:22 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/03 21:24:38 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_udigits_base(uintmax_t n, int base)
{
	int		digits;

	digits = 0;
	if (n == 0)
		digits++;
	while (n)
	{
		digits++;
		n /= base;
	}
	return (digits);
}
