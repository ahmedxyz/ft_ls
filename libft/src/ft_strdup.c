/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:30:49 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/16 10:18:22 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*d;

	if (!s)
		return (NULL);
	if (!(d = ft_strnew(ft_strlen(s))))
		return (NULL);
	ft_strcpy(d, s);
	return (d);
}
