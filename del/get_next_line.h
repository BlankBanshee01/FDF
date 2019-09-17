/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:26:33 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/11/12 22:40:26 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#define	GET_NEXT_LINE_H

#define BUFF_SIZE 30
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/libft.h"

int	get_next_line(const int fd, char **line);

# endif
