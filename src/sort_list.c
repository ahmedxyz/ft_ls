/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:50:17 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:07:23 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_list		*sort_list(t_list *list, t_option *option)
{
	int		sorted;
	t_list	*temp;

	sorted = 0;
	temp = NULL;
	while (sorted == 0)
	{
		sorted = 1;
		temp = list;
		while (temp->next != NULL)
		{
			if ((option->t == 1) ? compare_time(temp, temp->next) > 0 :
									compare_name(temp, temp->next) > 0)
			{
				sorted = 0;
				ft_lstswap(temp, temp->next);
			}
			temp = temp->next;
		}
	}
	if (option->r == 1)
		ft_lstrev(&list);
	return (list);
}

int			compare_time(t_list *current, t_list *next)
{
	time_t	current_time;
	time_t	next_time;

	current_time = ((t_file *)current->content)->stat.st_mtimespec.tv_sec;
	next_time = ((t_file *)next->content)->stat.st_mtimespec.tv_sec;
	if (current_time == next_time)
	{
		current_time = ((t_file *)current->content)->stat.st_mtimespec.tv_nsec;
		next_time = ((t_file *)next->content)->stat.st_mtimespec.tv_nsec;
		if (current_time == next_time)
			return (compare_name(current, next));
		return (current_time < next_time);
	}
	return (current_time < next_time);
}

int			compare_name(t_list *current, t_list *next)
{
	char	*current_name;
	char	*next_name;

	current_name = ((t_file *)current->content)->name;
	next_name = ((t_file *)next->content)->name;
	return (ft_strcmp(current_name, next_name));
}
