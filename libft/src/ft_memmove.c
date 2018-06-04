/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 22:39:20 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/09 16:02:14 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;
	size_t		i;

	cdst = (char *)dst;
	csrc = (const char *)src;
	i = 0;
	if (src < dst)
	{
		while (len--)
			cdst[len] = csrc[len];
		return (dst);
	}
	while (i < len)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
