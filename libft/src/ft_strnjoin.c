/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:13:24 by hahmed            #+#    #+#             */
/*   Updated: 2018/01/27 09:21:42 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*s;

	if (!(s = ft_strnew(ft_strlen(s1) + n)))
		return (NULL);
	ft_strcpy(s, s1);
	ft_strncat(s, s2, n);
	return (s);
}
