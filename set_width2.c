/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:56:23 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/09 12:09:55 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_field5(t_width *width, t_file *current)
{
	if (width->field5 < ft_digits(minor(current->stat.st_rdev)))
		width->field5 = ft_digits(minor(current->stat.st_rdev));
}

void	set_field6(t_width *width, t_file *current)
{
	if (width->field6 < ft_digits(current->stat.st_size))
		width->field6 = ft_digits(current->stat.st_size);
}

void	set_field7(t_width *width, t_file *current)
{
	if (width->field7 < (int)ft_strlen(current->name))
		width->field7 = (int)ft_strlen(current->name);
}
