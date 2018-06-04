/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:36:56 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/08 10:54:59 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			j++;
			if (!little[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
