/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:58:44 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:11:22 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_links(t_file *file, int width)
{
	ft_printf("%*ld", width, file->stat.st_nlink);
}

void	display_user(t_file *file, t_option *option, int width)
{
	if (getpwuid(file->stat.st_uid) != NULL && option->n == 0)
		ft_printf(" %-*s ", width, getpwuid(file->stat.st_uid)->pw_name);
	else
		ft_printf(" %-*ld ", width, file->stat.st_uid);
}

void	display_group(t_file *file, t_option *option, int width)
{
	if (getgrgid(file->stat.st_gid) != NULL && option->n == 0)
		ft_printf(" %-*s ", width, getgrgid(file->stat.st_gid)->gr_name);
	else
		ft_printf(" %-*ld ", width, file->stat.st_gid);
}

void	display_major(t_file *file, int width)
{
	if (S_ISLNK(file->stat.st_mode))
		ft_printf("  %*s ", width, "");
	else
		ft_printf("  %*ld,", width, major(file->stat.st_rdev));
}

void	display_minor(t_file *file, int width)
{
	ft_printf(" %*ld ", width, minor(file->stat.st_rdev));
}
