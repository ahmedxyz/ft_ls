/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:51:42 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:53:17 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	split_list(t_list **list, t_list **files, t_list **dirs)
{
	t_list	*head;

	head = *list;
	while (*list != NULL)
	{
		if (S_ISDIR(((t_file *)(*list)->content)->stat.st_mode))
		{
			*dirs = (t_list *)ft_memalloc(sizeof(t_list));
			*dirs = ft_memcpy(*dirs, *list, sizeof(t_list));
			dirs = &(*dirs)->next;
		}
		else
		{
			*files = (t_list *)ft_memalloc(sizeof(t_list));
			*files = ft_memcpy(*files, *list, sizeof(t_list));
			files = &(*files)->next;
		}
		list = &(*list)->next;
	}
	*files = NULL;
	*dirs = NULL;
	free(head);
}
