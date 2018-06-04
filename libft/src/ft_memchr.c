/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 23:00:27 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/09 15:43:46 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*cs;
	size_t				i;

	cs = (unsigned const char *)s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
