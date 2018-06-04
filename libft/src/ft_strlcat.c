/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 13:20:15 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/09 17:13:46 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dst_len < size)
	{
		ft_strncat(dst, src, size - dst_len - 1);
		return (dst_len + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
