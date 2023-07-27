/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:56:27 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/29 16:59:28 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_num(t_arg_format fmt, va_list *arg);
size_t	ft_write_str(t_arg_format fmt, va_list *arg);
size_t	ft_write_chr(t_arg_format fmt, va_list *arg);
size_t	ft_write_pntr(t_arg_format fmt, va_list *arg);

size_t	ft_write_arg(t_arg_format fmt, va_list *arg)
{
	size_t	n;

	n = 0;
	if (!fmt.error)
	{
		if (fmt.spec.bit.intr || fmt.spec.bit.unsign
			|| fmt.spec.bit.hex || fmt.spec.bit.oct || fmt.spec.bit.bin)
			n = ft_write_num (fmt, arg);
		else if (fmt.spec.bit.str)
			n = ft_write_str (fmt, arg);
		else if (fmt.spec.bit.chr || fmt.flag.bit.pcnt)
			n = ft_write_chr (fmt, arg);
		else if (fmt.spec.bit.pntr)
			n = ft_write_pntr (fmt, arg);
	}
	return (n);
}
