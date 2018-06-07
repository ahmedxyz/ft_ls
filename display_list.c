/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:29:52 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/07 07:01:08 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_row(t_list *current, int width, int cols, int rows)
{
	int		x;
	int		y;

	x = 0;
	while (current != NULL && x < cols)
	{
		ft_printf("%-*s", width, ((t_file *)current->content)->name);
		y = 0;
		while (current != NULL && y < rows)
		{
			current = current->next;
			y++;
		}
		x++;
	}
	ft_printf("\n");
}

void		display_columns(t_list *current, t_option *option, int width)
{
	struct ttysize	ttysize;
	int				cols;
	int				rows;
	int				y;
	t_list			*next;

	ioctl(0, TIOCGWINSZ, &ttysize);
	cols = (option->one == 1) ? 1 : (ttysize.ts_cols / width);
	rows = (ft_lstsize(current) / cols) + (ft_lstsize(current) % cols ? 1 : 0);
	y = 0;
	while (current != NULL && y < rows)
	{
		next = current->next;
		display_row(current, width, cols, rows);
		current = next;
		y++;
	}
	free(next);
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
	ft_lstdel(&child, free_file);
}

void		display_directory(t_list *current, t_option *option)
{
	DIR		*directory;
	t_list	*child;
	t_width	*width;

	if ((directory = opendir(((t_file *)current->content)->path)) == NULL)
		error_no_such_file(((t_file *)current->content)->name);
	if (!(child = listify_dir(directory, (t_file *)current->content, option)))
		return ;
	closedir(directory);
	child = sort_list(child, option);
	width = set_width(child, option);
	if (option->l == 1)
	{
		ft_printf("total %zu\n", get_total(child));
		display_longs(child, option, width);
	}
	else
		display_columns(child, option, width->field7);
	free(width);
	if (option->rr == 1)
		display_recursive(child, option);
	else
		ft_lstdel(&child, free_file);
}

void		display_list(t_list *files, t_list *dirs, t_option *option)
{
	t_width	*width;
	int		files_size;
	int		dirs_size;

	width = set_width(files, option);
	files_size = ft_lstsize(files);
	dirs_size = ft_lstsize(dirs);
	if (option->l == 1)
		display_longs(files, option, width);
	else
		display_columns(files, option, width->field7);
	if (files_size > 0 && dirs_size > 0)
		ft_printf("\n");
	while (dirs != NULL)
	{
		if (files_size > 0 || dirs_size > 1)
			ft_printf("%s:\n", ((t_file *)dirs->content)->name);
		display_directory(dirs, option);
		if (dirs->next != NULL)
			ft_printf("\n");
		dirs = dirs->next;
	}
	free(width);
}
