/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:16:07 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/04/11 18:43:46 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_format(t_arg_format *fmt, char *format);
size_t	ft_write_arg(t_arg_format fmt, va_list *arg);

int	ft_printf(const char *format, ...)
{
	va_list			arg;
	t_arg_format	fmt;
	size_t			num;

	va_start (arg, format);
	num = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write (1, format, 1);
			format++;
			num++;
			continue ;
		}
		format++;
		format = ft_read_format (&fmt, (char *) format);
		if (fmt.error)
			return (-1);
		num += ft_write_arg(fmt, &arg);
	}
	return (num);
}
