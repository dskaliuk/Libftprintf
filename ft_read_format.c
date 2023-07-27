/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:40:57 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/29 16:31:51 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_flag(t_arg_format *fmt, char *s);
char	*ft_read_width(t_arg_format *fmt, char *s);
char	*ft_read_prec(t_arg_format *fmt, char *s);
char	*ft_read_size(t_arg_format *fmt, char *s);
char	*ft_read_specifier(t_arg_format *fmt, char *s);

char	*ft_read_format(t_arg_format *fmt, char *format)
{
	fmt->error = 0;
	fmt->flag.byte = 0;
	fmt->width = 0;
	fmt->prec = 0;
	fmt->size.byte = 0;
	fmt->spec.byte = 0;
	format = ft_read_flag (fmt, format);
	format = ft_read_width (fmt, format);
	format = ft_read_prec (fmt, format);
	format = ft_read_size (fmt, format);
	format = ft_read_specifier (fmt, format);
	if (!fmt->spec.byte && !fmt->flag.bit.pcnt)
		fmt->error = 1;
	return (format);
}
