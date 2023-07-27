/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:40:57 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/29 16:31:51 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_flag(t_arg_format *fmt, char *s)
{
	while (*s == '-' || *s == '+' || *s == ' ' || *s == '#' || *s == '0')
	{
		if (*s == '-')
			fmt->flag.bit.menos = 1;
		else if (*s == '+')
			fmt->flag.bit.plus = 1;
		else if (*s == ' ')
			fmt->flag.bit.space = 1;
		else if (*s == '#')
			fmt->flag.bit.alt = 1;
		else if (*s == '0')
			fmt->flag.bit.zero = 1;
		s++;
	}
	return (s);
}
