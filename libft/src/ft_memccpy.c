/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 22:19:22 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/09 15:41:31 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*cdst;
	unsigned const char	*csrc;
	size_t				i;

	cdst = (unsigned char *)dst;
	csrc = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		*cdst = *csrc;
		cdst++;
		if (*csrc == (unsigned char)c)
			return ((void *)cdst);
		csrc++;
		i++;
	}
	return (NULL);
}
