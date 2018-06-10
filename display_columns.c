/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_columns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:54:23 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:09:00 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_columns(t_list *current, t_option *option, int width)
{
	struct ttysize	ttysize;
	int				cols;
	int				rows;
	int				y;
	t_list			*next;

	ioctl(0, TIOCGWINSZ, &ttysize);
	cols = (option->one == 1) ? 1 : (ttysize.ts_cols / width);
	rows = (ft_lstsize(current) / cols) + (ft_lstsize(current) % cols ? 1 : 0);
	y = 0;
	while (current != NULL && y < rows)
	{
		next = current->next;
		display_row(current, width, cols, rows);
		current = next;
		y++;
	}
}

void	display_row(t_list *current, int width, int cols, int rows)
{
	int	x;
	int	y;

	x = 0;
	while (current != NULL && x < cols)
	{
		ft_printf("%-*s", width, ((t_file *)current->content)->name);
		y = 0;
		while (current != NULL && y < rows)
		{
			current = current->next;
			y++;
		}
		x++;
	}
	ft_printf("\n");
}
