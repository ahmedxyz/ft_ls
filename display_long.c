/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:43:46 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/04 10:33:36 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

blkcnt_t	get_total(t_list *current)
{
	blkcnt_t	total;

	total = 0;
	while (current != NULL)
	{
		total += ((t_file *)current->content)->stat.st_blocks;
		current = current->next;
	}
	return (total);
}

char		get_filetype(t_file *current)
{
	if (S_ISDIR(current->stat.st_mode))
		return ('d');
	else if (S_ISCHR(current->stat.st_mode))
		return ('c');
	else if (S_ISBLK(current->stat.st_mode))
		return ('b');
	else if (S_ISSOCK(current->stat.st_mode))
		return ('s');
	else if (S_ISFIFO(current->stat.st_mode))
		return ('p');
	else if (S_ISLNK(current->stat.st_mode))
		return ('l');
	else
		return ('-');
}

char		get_suffix(t_file *current)
{
	char	xattr[4096];

	if (listxattr(current->path, xattr, sizeof(xattr), XATTR_NOFOLLOW) > 0)
		return ('@');
	else if (acl_get_link_np(current->path, ACL_TYPE_EXTENDED) != NULL)
		return ('+');
	else
		return (' ');
}

void		display_permissions(t_file *current)
{
	char	permissions[12];

	permissions[0] = get_filetype(current);
	permissions[1] = (current->stat.st_mode & S_IRUSR) ? 'r' : '-';
	permissions[2] = (current->stat.st_mode & S_IWUSR) ? 'w' : '-';
	permissions[3] = (current->stat.st_mode & S_IXUSR) ? 'x' : '-';
	permissions[4] = (current->stat.st_mode & S_IRGRP) ? 'r' : '-';
	permissions[5] = (current->stat.st_mode & S_IWGRP) ? 'w' : '-';
	permissions[6] = (current->stat.st_mode & S_IXGRP) ? 'x' : '-';
	permissions[7] = (current->stat.st_mode & S_IROTH) ? 'r' : '-';
	permissions[8] = (current->stat.st_mode & S_IWOTH) ? 'w' : '-';
	permissions[9] = (current->stat.st_mode & S_IXOTH) ? 'x' : '-';
	permissions[10] = get_suffix(current);
	permissions[11] = '\0';
	if (current->stat.st_mode & S_ISUID)
		permissions[3] = (permissions[3] == '-') ? 'S' : 's';
	if (current->stat.st_mode & S_ISGID)
		permissions[6] = (permissions[6] == '-') ? 'S' : 's';
	if (current->stat.st_mode & S_ISVTX)
		permissions[9] = (permissions[9] == '-') ? 'T' : 't';
	ft_printf("%s", permissions);
}

void		display_links(t_file *current, int width)
{
	ft_printf(" %*ld", width, current->stat.st_nlink);
}

void		display_user(t_file *current, t_option *option, int width)
{
	if (getpwuid(current->stat.st_uid) != NULL && option->n == 0)
		ft_printf(" %-*s ", width, getpwuid(current->stat.st_uid)->pw_name);
	else
		ft_printf(" %-*ld ", width, current->stat.st_uid);
}

void		display_group(t_file *current, t_option *option, int width)
{
	if (getgrgid(current->stat.st_gid) != NULL && option->n == 0)
		ft_printf(" %-*s ", width, getgrgid(current->stat.st_gid)->gr_name);
	else
		ft_printf(" %-*ld ", width, current->stat.st_gid);
}

void		display_major(t_file *current, int width)
{
	if (S_ISLNK(current->stat.st_mode))
		ft_printf("  %*s ", width, "");
	else
		ft_printf("  %*ld,", width, major(current->stat.st_rdev));
}

void		display_minor(t_file *current, int width)
{
	ft_printf(" %*ld ", width, minor(current->stat.st_rdev));
}

void		display_size(t_file *current, int width)
{
	ft_printf(" %*lld ", width, current->stat.st_size);
}

void		display_time(t_file *current, t_option *option)
{
	time_t		present_time;
	time_t		file_time;
	char		*string;

	present_time = time(NULL);
	file_time = current->stat.st_mtime;
	string = ctime(&file_time);
	ft_printf("%.*s ", 6, string + 4);
	if (option->tt == 1)
		ft_printf("%.*s ", 13, string + 11);
	else if (file_time < present_time - 15552000 || present_time < file_time)
		ft_printf(" %.*s ", 4, string + 20);
	else
		ft_printf("%.*s ", 5, string + 11);
}

void		display_name(t_file *current)
{
	char		linkname[4096];

	ft_printf("%s", current->name);
	if (S_ISLNK(current->stat.st_mode))
	{
		ft_bzero(linkname, sizeof(linkname));
		if (readlink(current->path, linkname, sizeof(linkname)) == -1)
			error_no_such_file(current->name);
		ft_printf(" -> %s", linkname);
	}
}

void		display_long(t_file *current, t_option *option, t_width *width)
{
	display_permissions(current);
	display_links(current, width->field1);
	if (option->g == 0)
		display_user(current, option, width->field2);
	if (option->o == 0)
		display_group(current, option, width->field3);
	if (S_ISBLK(current->stat.st_mode) || S_ISCHR(current->stat.st_mode))
	{
		display_major(current, width->field4);
		display_minor(current, width->field5);
	}
	else
		display_size(current, width->field6);
	display_time(current, option);
	display_name(current);
	ft_printf("\n");
}

void		display_longs(t_list *current, t_option *option, t_width *width)
{
	while (current != NULL)
	{
		display_long((t_file *)current->content, option, width);
		current = current->next;
	}
}
