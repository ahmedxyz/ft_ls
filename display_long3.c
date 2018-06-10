/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:59:26 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:11:47 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_size(t_file *file, int width)
{
	ft_printf(" %*lld ", width, file->stat.st_size);
}

void	display_time(t_file *file, t_option *option)
{
	time_t	now;
	time_t	last_mod;
	char	*string;

	now = time(NULL);
	last_mod = file->stat.st_mtime;
	string = ctime(&last_mod);
	ft_printf("%.*s ", 6, string + 4);
	if (option->tt == 1)
		ft_printf("%.*s ", 13, string + 11);
	else if (last_mod < now - 15552000 || now < last_mod)
		ft_printf(" %.*s ", 4, string + 20);
	else
		ft_printf("%.*s ", 5, string + 11);
}

void	display_name(t_file *file)
{
	char	linkname[4096];

	ft_printf("%s", file->name);
	if (S_ISLNK(file->stat.st_mode))
	{
		ft_bzero(linkname, sizeof(linkname));
		if (readlink(file->path, linkname, sizeof(linkname)) == -1)
			print_file_error(file->name);
		ft_printf(" -> %s", linkname);
	}
}
