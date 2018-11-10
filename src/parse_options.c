/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:46:57 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:03:44 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_option	*parse_options(int argc, char **argv)
{
	t_option	*option;
	int			i;
	int			j;

	option = (t_option *)ft_memalloc(sizeof(t_option));
	i = 1;
	while (i < argc)
	{
		j = 1;
		while (argv[i][0] == '-' && argv[i][j] != '\0')
		{
			if (ft_strchr("ACRTadglnort1", argv[i][j]) != NULL)
				set_option(argv[i][j], option);
			else
				print_option_error(argv[i][j]);
			j++;
		}
		i++;
	}
	return (option);
}

void		set_option(char c, t_option *option)
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
