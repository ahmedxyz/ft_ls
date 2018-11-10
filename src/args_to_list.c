/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:49:03 by hahmed            #+#    #+#             */
/*   Updated: 2018/11/10 00:13:22 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_list		*args_to_list(int argc, char **argv)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 1;
	while (argv[i] != NULL && argv[i][0] == '-' && argv[i][1] != '\0')
		i++;
	if (i == argc)
		add_file_to_list(&list, ".", NULL);
	else
	{
		while (i < argc)
		{
			if (file_exists(argv[i]) == 1)
				add_file_to_list(&list, argv[i], NULL);
			else
				print_file_error(argv[i]);
			i++;
		}
	}
	return (list);
}

int			file_exists(char *name)
{
	struct stat		buffer;

	if (lstat(name, &buffer) == 0)
		return (1);
	return (0);
}

void		add_file_to_list(t_list **list, char *name, char *path)
{
	t_file	*file;

	file = (t_file *)ft_memalloc(sizeof(t_file));
	file->name = ft_strdup(name);
	file->path = (path != NULL) ? ft_strjoin(path, name) : ft_strdup(name);
	lstat(file->path, &file->stat);
	if (S_ISDIR(file->stat.st_mode))
		file->path = ft_strjoin_free(file->path, "/");
	ft_lstaddback(list, ft_lstnew(file, sizeof(t_file)));
	free(file);
}
