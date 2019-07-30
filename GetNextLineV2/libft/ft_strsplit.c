/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:26:42 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/10/24 18:35:21 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_cc(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static unsigned int	ft_wcount(const char *str, char c)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (str[i] != c && str[i])
		a++;
	while (str[i])
	{
		if (str[i + 1] != c && str[i + 1] && str[i] == c)
			a++;
		i++;
	}
	return (a);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	f;
	char	**tab;

	f = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc((ft_wcount(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (*s && ft_wcount(s, c) > 0)
	{
		while (*s == c && *s)
			s++;
		while (*s && *s != c)
		{
			if (!(tab[f] = ft_strsub(s, 0, ft_cc(s, c))))
				return (NULL);
			f++;
			s = s + ft_cc(s, c);
		}
	}
	tab[f] = 0;
	return (tab);
}
