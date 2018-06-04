/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:43:39 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/06 01:43:58 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fs;
	size_t	i;

	if (!s || !f)
		return (NULL);
	fs = ft_strdup(s);
	if (!fs)
		return (NULL);
	i = 0;
	while (s[i])
	{
		fs[i] = f(s[i]);
		i++;
	}
	fs[i] = '\0';
	return (fs);
}
