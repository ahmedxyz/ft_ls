/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:06:00 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/20 04:15:22 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*append(char *s, char c)
{
	int		len;
	char	*new;

	len = ft_strlen(s);
	new = ft_strnew(len + 1);
	ft_strncpy(new, s, len);
	new[len] = c;
	new[len + 1] = '\0';
	free(s);
	return (new);
}

char	*prepend(char *s, char c)
{
	int		len;
	char	*new;

	len = ft_strlen(s);
	new = ft_strnew(len + 1);
	new[0] = c;
	ft_strncpy(new + 1, s, len);
	new[len + 1] = '\0';
	free(s);
	return (new);
}

char	*trim_first(char *s)
{
	int		len;
	char	*new;

	len = ft_strlen(s) - 1;
	new = ft_strnew(len);
	ft_strncpy(new, s + 1, len);
	new[len] = '\0';
	free(s);
	return (new);
}

char	*ft_strtoupper(char *s)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
	{
		*tmp = ft_toupper(*tmp);
		tmp++;
	}
	return (s);
}

char	*ft_strjoin_wrapper(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (new);
}
