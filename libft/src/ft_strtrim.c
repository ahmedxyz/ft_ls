/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:44:11 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/09 17:17:50 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*ss;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	while (ft_iswhitespace(s[i++]))
		start++;
	while (s[i])
	{
		if (ft_iswhitespace(s[i]))
			end++;
		else
			end = 0;
		i++;
	}
	if (!(ss = ft_strnew(ft_strlen(s) - start - end)))
		return (NULL);
	return (ft_strncpy(ss, s + start, ft_strlen(s) - start - end));
}
