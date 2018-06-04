/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:31:35 by hahmed            #+#    #+#             */
/*   Updated: 2018/03/31 18:02:50 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*s;
	int		digits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = ft_strnew(ft_digits(n) + 1);
	digits = ft_digits(n) - 1;
	if (s)
	{
		if (n < 0)
		{
			s[0] = '-';
			n *= -1;
		}
		if (n == 0)
			s[0] = '0';
		while (n > 0)
		{
			s[digits] = '0' + (n % 10);
			n /= 10;
			digits--;
		}
	}
	return (s);
}
