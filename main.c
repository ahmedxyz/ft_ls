/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:45:56 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:06:17 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_option	*option;
	t_list		*list;
	t_list		*files;
	t_list		*dirs;

	option = parse_options(argc, argv);
	list = listify_args(argc, argv);
	list = sort_list(list, option);
	if (option->d == 1)
	{
		display_list(list, NULL, option);
		ft_lstdel(&list, free_file);
	}
	else
	{
		split_list(&list, &files, &dirs);
		display_list(files, dirs, option);
		ft_lstdel(&files, free_file);
		ft_lstdel(&dirs, free_file);
	}
	free(option);
	return (0);
}
