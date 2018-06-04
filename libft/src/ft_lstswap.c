/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:53:21 by hahmed            #+#    #+#             */
/*   Updated: 2018/05/21 19:00:54 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *a, t_list *b)
{
	ft_swapptr(&a->content, &b->content);
	ft_swap((int*)&a->content_size, (int*)&b->content_size);
}
