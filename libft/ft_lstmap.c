/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:40:05 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/09/30 21:40:07 by iet-tibi         ###   ########.fr       */
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
