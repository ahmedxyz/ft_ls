/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:57:12 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/07 06:18:58 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		file_exists(char *filename)
{
	struct stat		buffer;

	if (lstat(filename, &buffer) == -1)
		return (0);
	return (1);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	free(s1);
	return (new);
}

void	add_file(t_list **list, char *filename, char *path)
{
	t_file	*file;

	file = (t_file *)ft_memalloc(sizeof(t_file));
	file->name = ft_strdup(filename);
	file->path = (path != NULL) ? ft_strjoin(path, filename) :
									ft_strdup(filename);
	lstat(file->path, &file->stat);
	file->path = (S_ISDIR(file->stat.st_mode)) ? ft_strjoin1(file->path, "/") :
													file->path;
	ft_lstaddback(list, ft_lstnew(file, sizeof(t_file)));
	free(file);
}

t_list	*listify_args(int argc, char **argv)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 1;
	while (argv[i] != NULL && argv[i][0] == '-' && argv[i][1] != '\0')
		i++;
	if (i == argc)
		add_file(&list, ".", NULL);
	else
	{
		while (i < argc)
		{
			if (file_exists(argv[i]) == 1)
				add_file(&list, argv[i], NULL);
			else
				error_no_such_file(argv[i]);
			i++;
		}
	}
	return (list);
}

void	set_option(char c, t_option *option)
{
	(c == 'A') ? (option->aa = 1) : 0;
	(c == 'R') ? (option->rr = 1) : 0;
	(c == 'T') ? (option->tt = 1) : 0;
	(c == 'a') ? (option->a = 1) : 0;
	(c == 'd') ? (option->d = 1) : 0;
	(c == 'g') ? (option->g = 1) : 0;
	(c == 'l') ? (option->l = 1) : 0;
	(c == 'n') ? (option->n = 1) : 0;
	(c == 'o') ? (option->o = 1) : 0;
	(c == 'r') ? (option->r = 1) : 0;
	(c == 't') ? (option->t = 1) : 0;
	(c == '1') ? (option->one = 1) : 0;
	if (ft_strchr("Tgno", c) != NULL)
		option->l = 1;
}

void	parse_options(int argc, char **argv, t_option *option)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (argv[i][0] == '-' && argv[i][j] != '\0')
		{
			if (ft_strchr("ACRTadglnort1", argv[i][j]) != NULL)
				set_option(argv[i][j], option);
			else
				error_illegal_option(argv[i][j]);
			j++;
		}
		i++;
	}
}

void	split_list(t_list *list, t_list **files, t_list **dirs)
{
	while (list != NULL)
	{
		if (S_ISDIR(((t_file *)list->content)->stat.st_mode))
		{
			*dirs = (t_list *)malloc(sizeof(t_list));
			*dirs = ft_memcpy(*dirs, list, sizeof(*dirs));
			dirs = &(*dirs)->next;
		}
		else
		{
			*files = (t_list *)malloc(sizeof(t_list));
			*files = ft_memcpy(*files, list, sizeof(*files));
			files = &(*files)->next;
		}
		list = list->next;
	}
	*files = NULL;
	*dirs = NULL;
	ft_lstdel(&list, free_file);
}

void	free_file(void *content, size_t content_size)
{
	(void)content_size;
	free(((t_file *)content)->name);
	free(((t_file *)content)->path);
	free(content);
}

int		main(int argc, char **argv)
{
	t_option	*option;
	t_list		*list;
	t_list		*files;
	t_list		*dirs;

	option = (t_option *)ft_memalloc(sizeof(t_option));
	parse_options(argc, argv, option);
	list = listify_args(argc, argv);
	list = sort_list(list, option);
	if (option->d == 1)
	{
		display_list(list, NULL, option);
		ft_lstdel(&list, free_file);
	}
	else
	{
		split_list(list, &files, &dirs);
		display_list(files, dirs, option);
		ft_lstdel(&files, free_file);
		ft_lstdel(&dirs, free_file);
	}
	free(option);
	return (0);
}
