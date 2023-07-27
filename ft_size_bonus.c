/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:59:44 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/28 15:57:27 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_intsize_wr(t_arg_format fmt, va_list *arg)
{
	if (fmt.size.byte == 0)
		return (ft_ltoa (va_arg (*arg, int), 10, 0));
	else if (fmt.size.bit.chr)
		return (ft_ltoa ((char) va_arg (*arg, int), 10, 0));
	else if (fmt.size.bit.shrt)
		return (ft_ltoa ((short int) va_arg (*arg, int), 10, 0));
	else if (fmt.size.bit.lng)
		return (ft_ltoa ((long int) va_arg (*arg, long int), 10, 0));
	else
		return (ft_ltoa (va_arg (*arg, long long int), 10, 0));
}

char	*ft_uintsize_wr(t_arg_format fmt, va_list *arg, int base)
{
	if (fmt.size.byte == 0)
		return (ft_ultoa ((unsigned int) va_arg (*arg, unsigned int),
				base, fmt.flag.bit.up, 0));
	else if (fmt.size.bit.chr)
		return (ft_ultoa ((unsigned char) va_arg (*arg, unsigned int),
				base, fmt.flag.bit.up, 0));
	else if (fmt.size.bit.shrt)
		return (ft_ultoa ((unsigned short) va_arg (*arg, unsigned int),
				base, fmt.flag.bit.up, 0));
	else if (fmt.size.bit.lng)
		return (ft_ultoa ((unsigned long int) va_arg (*arg, unsigned long int),
				base, fmt.flag.bit.up, 0));
	else
		return (ft_ultoa (va_arg (*arg, unsigned long long int),
				base, fmt.flag.bit.up, 0));
}
