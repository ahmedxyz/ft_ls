/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:06:48 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/09 17:12:46 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_length(char const *s, char c)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		length++;
		i++;
	}
	return (length);
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	x;
	size_t	y;
	char	**words;

	if (!s || !(words = (char **)malloc(sizeof(*words)
					* (word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	x = 0;
	while (x < word_count(s, c))
	{
		y = 0;
		if (!(words[x] = ft_strnew(word_length(&s[i], c) + 1)))
			words[x] = NULL;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			words[x][y++] = s[i++];
		words[x][y] = '\0';
		x++;
	}
	words[x] = 0;
	return (words);
}
