/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:39:09 by hahmed            #+#    #+#             */
/*   Updated: 2017/09/26 17:51:50 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*temp;

	current = *alst;
	while (current)
	{
		del(current->content, current->content_size);
		temp = current;
		current = current->next;
		ft_memdel((void **)&temp);
	}
	*alst = NULL;
}
