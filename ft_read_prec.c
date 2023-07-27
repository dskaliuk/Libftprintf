/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_prec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:40:57 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/29 16:31:51 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_prec(t_arg_format *fmt, char *s)
{
	if (*s != '.')
		return (s);
	s++;
	fmt->flag.bit.prec = 1;
	while (*s >= '0' && *s <= '9')
	{
		fmt->prec = fmt->prec * 10 + *s - '0';
		s++;
	}
	return (s);
}
