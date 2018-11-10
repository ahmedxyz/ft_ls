/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 12:00:15 by hahmed            #+#    #+#             */
/*   Updated: 2018/11/09 23:45:33 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	free(s1);
	return (new);
}

void	free_file(void *content, size_t content_size)
{
	free(((t_file *)content)->name);
	free(((t_file *)content)->path);
	free((t_list *)content);
	(void)content_size;
}
