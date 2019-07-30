/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:35:32 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/25 17:02:26 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	lst = lst->next;
	head = new;
	while (lst != NULL)
	{
		new->next = f(lst);
		lst = lst->next;
		new = new->next;
	}
	new->next = NULL;
	return (head);
}
