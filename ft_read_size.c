/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:43:42 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/04/11 15:59:22 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_size(t_arg_format *fmt, char *s)
{
	if (*s == 'h' || *s == 'l' || *s == 'L')
	{
		if (*s == 'h' && *(s + 1) == 'h')
			fmt->size.bit.chr = 1;
		else if (*s == 'h')
			fmt->size.bit.shrt = 1;
		else if (*s == 'l' && *(s + 1) == 'l')
			fmt->size.bit.llng = 1;
		else if (*s == 'l')
				fmt->size.bit.lng = 1;
		s++;
		if (fmt->size.bit.chr || fmt->size.bit.llng)
			s++;
	}
	return (s);
}

/*
void	ft_write_fmt(t_arg_format fmt)
{
	printf ("------ flag ------\n");
	printf ("menos plus space alt zero pcnt up prec\n");
	printf ("%5d %4d %5d %3d %4d %4d %2d %4d\n", fmt.flag.bit.menos,
		fmt.flag.bit.plus, fmt.flag.bit.space, fmt.flag.bit.alt,
		fmt.flag.bit.zero, fmt.flag.bit.pcnt, fmt.flag.bit.up,
		fmt.flag.bit.prec);
	printf ("------ width = %2lu ------\n", fmt.width);
	printf ("------ prec  = %2lu ------\n", fmt.prec);
	printf ("------ size ------\n");
	printf ("chr shrt lng llng ldbl\n");
	printf ("%-3d %-4d %-3d %-4d %-4d \n", fmt.size.bit.chr,
		fmt.size.bit.shrt, fmt.size.bit.lng, fmt.size.bit.llng,
		fmt.size.bit.ldbl);
	printf ("------ spec ------\n");
	printf ("intr unsign hex chr str pntr oct bin\n");
	printf ("%-4d %-6d %-3d %-3d %-3d %-4d %-3d %-3d \n",
		fmt.spec.bit.intr, fmt.spec.bit.unsign,
		fmt.spec.bit.hex, fmt.spec.bit.chr, fmt.spec.bit.str,
		fmt.spec.bit.pntr, fmt.spec.bit.oct, fmt.spec.bit.bin);
}*/
