/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listify_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:30:01 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/07 06:20:27 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*listify_dir(DIR *directory, t_file *current, t_option *option)
{
	t_list			*child;
	struct dirent	*entry;

	child = NULL;
	entry = readdir(directory);
	while (entry != NULL)
	{
		if (option->a == 1)
			add_file(&child, entry->d_name, current->path);
		else if (option->a == 0 && entry->d_name[0] != '.')
			add_file(&child, entry->d_name, current->path);
		else if (option->aa == 1 && ft_strequ(entry->d_name, ".") == 0 &&
									ft_strequ(entry->d_name, "..") == 0)
			add_file(&child, entry->d_name, current->path);
		entry = readdir(directory);
	}
	free(entry);
	return (child);
}
