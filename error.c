/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:22:07 by hahmed            #+#    #+#             */
/*   Updated: 2018/06/04 10:33:23 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_illegal_option(char option)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putstr_fd("\nusage: ft_ls [-ACRTadglnort] [file ...]\n", 2);
	exit(1);
}

void	error_no_such_file(char *filename)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
