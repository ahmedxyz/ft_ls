/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:52:20 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:08:20 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_list(t_list *files, t_list *dirs, t_option *option)
{
	t_width	*width;
	int		files_size;
	int		dirs_size;

	width = set_width(files, option);
	files_size = ft_lstsize(files);
	dirs_size = ft_lstsize(dirs);
	if (option->l == 1)
		display_long(files, option, width);
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
