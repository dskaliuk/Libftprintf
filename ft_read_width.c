/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:40:57 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/29 16:31:51 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_width(t_arg_format *fmt, char *s)
{
	fmt->width = 0;
	while (*s >= '0' && *s <= '9')
	{
		fmt->width = fmt->width * 10 + *s - '0';
		s++;
	}
	return (s);
}
