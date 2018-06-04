/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:14:39 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/08 11:11:39 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (lst->next)
	{
		new = ft_lstmap(lst->next, f);
		ft_lstadd(&new, f(lst));
	}
	else
		new = f(lst);
	return (new);
}
