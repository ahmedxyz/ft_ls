/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:55:21 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:09:46 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_width		*set_width(t_list *current, t_option *option)
{
	t_width		*width;

	width = (t_width *)ft_memalloc(sizeof(t_width));
	while (current != NULL)
	{
		set_field1(width, current->content);
		set_field2(width, current->content, option);
		set_field3(width, current->content, option);
		set_field4(width, current->content);
		set_field5(width, current->content);
		set_field6(width, current->content);
		set_field7(width, current->content);
		current = current->next;
	}
	width->field7 += 2;
	return (width);
}

void		set_field1(t_width *width, t_file *current)
{
	if (width->field1 < ft_digits(current->stat.st_nlink))
		width->field1 = ft_digits(current->stat.st_nlink);
}

void		set_field2(t_width *width, t_file *current, t_option *option)
{
	if (getpwuid(current->stat.st_uid) != NULL && option->n == 0)
	{
		if (width->field2 <
						(int)ft_strlen(getpwuid(current->stat.st_uid)->pw_name))
			width->field2 = ft_strlen(getpwuid(current->stat.st_uid)->pw_name);
	}
	else
	{
		if (width->field2 < ft_digits(current->stat.st_uid))
			width->field2 = ft_digits(current->stat.st_uid);
	}
}

void		set_field3(t_width *width, t_file *current, t_option *option)
{
	if (getgrgid(current->stat.st_gid) != NULL && option->n == 0)
	{
		if (width->field3 <
						(int)ft_strlen(getgrgid(current->stat.st_gid)->gr_name))
			width->field3 = ft_strlen(getgrgid(current->stat.st_gid)->gr_name);
	}
	else
	{
		if (width->field3 < ft_digits(current->stat.st_gid))
			width->field3 = ft_digits(current->stat.st_gid);
	}
}

void		set_field4(t_width *width, t_file *current)
{
	if (width->field4 < ft_digits(major(current->stat.st_rdev)))
		width->field4 = ft_digits(major(current->stat.st_rdev));
}
