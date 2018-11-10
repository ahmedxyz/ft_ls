/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_directory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:53:09 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:15:07 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		display_directory(t_list *current, t_option *option)
{
	DIR		*directory;
	t_list	*child;
	t_width	*width;

	if ((directory = opendir(((t_file *)current->content)->path)) == NULL)
		print_file_error(((t_file *)current->content)->name);
	if (!(child = dir_to_list(directory, (t_file *)current->content, option)))
		return ;
	closedir(directory);
	child = sort_list(child, option);
	width = set_width(child, option);
	if (option->l == 1)
	{
		ft_printf("total %zu\n", get_total(child));
		display_long(child, option, width);
	}
	else
		display_columns(child, option, width->field7);
	if (option->rr == 1)
		display_recursive(child, option);
	ft_lstdel(&child, free_file);
	free(width);
}

t_list		*dir_to_list(DIR *directory, t_file *current, t_option *option)
{
	t_list			*child;
	struct dirent	*entry;

	child = NULL;
	entry = readdir(directory);
	while (entry != NULL)
	{
		if (option->a == 1)
			add_file_to_list(&child, entry->d_name, current->path);
		else if (option->aa == 1 && ft_strequ(entry->d_name, ".") == 0 &&
									ft_strequ(entry->d_name, "..") == 0)
			add_file_to_list(&child, entry->d_name, current->path);
		else if (entry->d_name[0] != '.')
			add_file_to_list(&child, entry->d_name, current->path);
		entry = readdir(directory);
	}
	free(entry);
	return (child);
}

void		display_recursive(t_list *child, t_option *option)
{
	while (child != NULL)
	{
		if (S_ISDIR(((t_file *)child->content)->stat.st_mode) &&
		ft_strequ(((t_file *)child->content)->name, ".") == 0 &&
		ft_strequ(((t_file *)child->content)->name, "..") == 0)
		{
			ft_printf("\n%.*s:\n",
				ft_strlen(((t_file *)child->content)->path) - 1,
				((t_file *)child->content)->path);
			display_directory(child, option);
		}
		child = child->next;
	}
}
