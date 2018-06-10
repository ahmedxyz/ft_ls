/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:57:00 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:10:33 by hahmed           ###   ########.fr       */
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

void		display_long(t_list *current, t_option *option, t_width *width)
{
	t_file	*file;

	while (current != NULL)
	{
		file = (t_file *)current->content;
		display_permissions(file);
		display_links(file, width->field1);
		if (option->g == 0)
			display_user(file, option, width->field2);
		if (option->o == 0)
			display_group(file, option, width->field3);
		if (S_ISBLK(file->stat.st_mode) || S_ISCHR(file->stat.st_mode))
		{
			display_major(file, width->field4);
			display_minor(file, width->field5);
		}
		else
			display_size(file, width->field6);
		display_time(file, option);
		display_name(file);
		ft_printf("\n");
		current = current->next;
	}
}

char		get_filetype(t_file *file)
{
	if (S_ISDIR(file->stat.st_mode))
		return ('d');
	else if (S_ISCHR(file->stat.st_mode))
		return ('c');
	else if (S_ISBLK(file->stat.st_mode))
		return ('b');
	else if (S_ISSOCK(file->stat.st_mode))
		return ('s');
	else if (S_ISFIFO(file->stat.st_mode))
		return ('p');
	else if (S_ISLNK(file->stat.st_mode))
		return ('l');
	else
		return ('-');
}

char		get_suffix(t_file *file)
{
	char	xattr[4096];

	if (listxattr(file->path, xattr, sizeof(xattr), XATTR_NOFOLLOW) > 0)
		return ('@');
	else if (acl_get_link_np(file->path, ACL_TYPE_EXTENDED) != NULL)
		return ('+');
	else
		return (' ');
}

void		display_permissions(t_file *file)
{
	char	permissions[12];

	permissions[0] = get_filetype(file);
	permissions[1] = (file->stat.st_mode & S_IRUSR) ? 'r' : '-';
	permissions[2] = (file->stat.st_mode & S_IWUSR) ? 'w' : '-';
	permissions[3] = (file->stat.st_mode & S_IXUSR) ? 'x' : '-';
	permissions[4] = (file->stat.st_mode & S_IRGRP) ? 'r' : '-';
	permissions[5] = (file->stat.st_mode & S_IWGRP) ? 'w' : '-';
	permissions[6] = (file->stat.st_mode & S_IXGRP) ? 'x' : '-';
	permissions[7] = (file->stat.st_mode & S_IROTH) ? 'r' : '-';
	permissions[8] = (file->stat.st_mode & S_IWOTH) ? 'w' : '-';
	permissions[9] = (file->stat.st_mode & S_IXOTH) ? 'x' : '-';
	permissions[10] = get_suffix(file);
	permissions[11] = '\0';
	if (file->stat.st_mode & S_ISUID)
		permissions[3] = (permissions[3] == '-') ? 'S' : 's';
	if (file->stat.st_mode & S_ISGID)
		permissions[6] = (permissions[6] == '-') ? 'S' : 's';
	if (file->stat.st_mode & S_ISVTX)
		permissions[9] = (permissions[9] == '-') ? 'T' : 't';
	ft_printf("%s ", permissions);
}
