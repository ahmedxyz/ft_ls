/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:15:26 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/09 16:55:20 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *)big + i);
	while (big[i])
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j < len))
		{
			j++;
			if (!little[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
