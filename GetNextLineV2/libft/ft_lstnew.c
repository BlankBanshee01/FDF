/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:26:35 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/24 20:09:48 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*k;

	if (!(k = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		k->content = NULL;
		k->content_size = 0;
	}
	else
	{
		k->content = ft_strdup((char *)content);
		k->content_size = content_size;
	}
	k->next = NULL;
	return (k);
}
