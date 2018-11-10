/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:55:12 by hahmed            #+#    #+#             */
/*   Updated: 2018/11/10 01:05:35 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
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

int				main(int argc, char **argv);

/*
** parse_options.c
*/

t_option		*parse_options(int argc, char **argv);
void			set_option(char c, t_option *option);

/*
** args_to_list.c
*/

t_list			*args_to_list(int argc, char **argv);
int				file_exists(char *name);
void			add_file_to_list(t_list **list, char *name, char *path);

/*
** sort_list.c
*/

t_list			*sort_list(t_list *list, t_option *option);
int				compare_time(t_list *current, t_list *next);
int				compare_name(t_list *current, t_list *next);

/*
** split_list.c
*/

void			split_list(t_list **list, t_list **files, t_list **dirs);

/*
** display_list.c
*/

void			display_list(t_list	*files, t_list *dirs, t_option *option);

/*
** display_directory.c
*/

void			display_directory(t_list *current, t_option *option);
t_list			*dir_to_list(DIR *directory, t_file *current, t_option *option);
void			display_recursive(t_list *child, t_option *option);

/*
** set_width1.c
*/

t_width			*set_width(t_list *current, t_option *option);
void			set_field1(t_width *width, t_file *current);
void			set_field2(t_width *width, t_file *current, t_option *option);
void			set_field3(t_width *width, t_file *current, t_option *option);
void			set_field4(t_width *width, t_file *current);

/*
** set_width2.c
*/

void			set_field5(t_width *width, t_file *current);
void			set_field6(t_width *width, t_file *current);
void			set_field7(t_width *width, t_file *current);

/*
** display_long1.c
*/

blkcnt_t		get_total(t_list *current);
void			display_long(t_list *current, t_option *option, t_width *width);
char			get_filetype(t_file *file);
char			get_suffix(t_file *file);
void			display_permissions(t_file *file);

/*
** display_long2.c
*/

void			display_links(t_file *file, int width);
void			display_user(t_file *file, t_option *option, int width);
void			display_group(t_file *file, t_option *option, int width);
void			display_major(t_file *file, int width);
void			display_minor(t_file *file, int width);

/*
** display_long3.c
*/

void			display_size(t_file *file, int width);
void			display_time(t_file *file, t_option *option);
void			display_name(t_file *file);

/*
** display_columns.c
*/

void			display_columns(t_list *current, t_option *option, int width);
void			display_row(t_list *current, int width, int cols, int rows);

/*
** free.c
*/

char			*ft_strjoin_free(char *s1, char *s2);
void			free_file(void *content, size_t content_size);

/*
** error.c
*/

void			print_option_error(char option);
void			print_file_error(char *name);

#endif
