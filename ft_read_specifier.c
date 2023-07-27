/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:40:57 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/29 16:31:51 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_specifier(t_arg_format *fmt, char *s)
{
	if (*s == 'd' || *s == 'i')
		fmt->spec.bit.intr = 1;
	else if (*s == 'u')
		fmt->spec.bit.unsign = 1;
	else if (*s == 'x' || *s == 'X')
		fmt->spec.bit.hex = 1;
	else if (*s == 'c')
		fmt->spec.bit.chr = 1;
	else if (*s == 's')
		fmt->spec.bit.str = 1;
	else if (*s == 'p')
		fmt->spec.bit.pntr = 1;
	else if (*s == 'o')
		fmt->spec.bit.oct = 1;
	else if (*s == 'b')
		fmt->spec.bit.bin = 1;
	else if (*s == '%')
		fmt->flag.bit.pcnt = 1;
	if (fmt->spec.bit.hex && *s == 'X')
			fmt->flag.bit.up = 1;
	if (fmt->spec.byte || fmt->flag.bit.pcnt)
		s++;
	return (s);
}
