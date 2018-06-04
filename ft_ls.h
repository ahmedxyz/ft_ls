/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:55:12 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/04 10:35:16 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <limits.h>
# include <pwd.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>

typedef struct	s_option
{
	int			aa;
	int			rr;
	int			tt;
	int			a;
	int			d;
	int			g;
	int			l;
	int			n;
	int			o;
	int			r;
	int			t;
	int			one;
}				t_option;

typedef struct	s_file
{
	char		*name;
	char		*path;
	struct stat	stat;
}				t_file;

typedef struct	s_width
{
	int			field1;
	int			field2;
	int			field3;
	int			field4;
	int			field5;
	int			field6;
	int			field7;
}				t_width;

/*
** main.c
*/

int				file_exists(char *filename);
void			add_file(t_list **list, char *filename, char *path);
t_list			*listify_args(int argc, char **argv);
void			set_option(char c, t_option *option);
void			parse_options(int argc, char **argv, t_option *option);
void			split_list(t_list *list, t_list **files, t_list **dirs);
int				main(int argc, char **argv);

/*
** error.c
*/

void			error_illegal_option(char option);
void			error_no_such_file(char *filename);

/*
** sort.c
*/

int				compare_name(t_list *current, t_list *next);
int				compare_time(t_list *current, t_list *next);
t_list			*sort_list(t_list *list, t_option *option);

/*
** listify_dir.c
*/

t_list			*listify_dir(DIR *directory, t_file *current, t_option *option);

/*
** display_list.c
*/

void			display_row(t_list *current, int width, int cols, int rows);
void			display_columns(t_list *current, t_option *option, int width);
void			display_directory(t_list *current, t_option *option);
void			display_recursive(t_list *child, t_option *option);
void			display_list(t_list	*files, t_list *dirs, t_option *option);

/*
** display_long.c
*/

blkcnt_t		get_total(t_list *current);
void			display_permissions(t_file *current);
void			display_time(t_file *current, t_option *option);
void			display_name(t_file *current);
void			display_long(t_file *current, t_option *option, t_width *width);
void			display_longs(t_list *current, t_option *option, t_width *width);

/*
** width.c
*/

void			set_field1(t_width *width, t_file *current);
void			set_field2(t_width *width, t_file *current, t_option *option);
void			set_field3(t_width *width, t_file *current, t_option *option);
void			set_field4(t_width *width, t_file *current);
void			set_field5(t_width *width, t_file *current);
void			set_field6(t_width *width, t_file *current);
void			set_field7(t_width *width, t_file *current);
t_width			*set_width(t_list *current, t_option *option);

#endif
