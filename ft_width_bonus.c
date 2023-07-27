/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:17:27 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/04/11 16:34:24 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prec(char *str, t_arg_format fmt, size_t width);

char	*ft_width(char *str, t_arg_format fmt)
{
	char	*s;
	size_t	len;

	if (fmt.flag.bit.zero && fmt.spec.byte & 0b11100111
		&& !fmt.flag.bit.menos && !fmt.flag.bit.prec)
			str = ft_prec (str, fmt, fmt.width);
	if (!str)
		return (str);
	len = ft_strlen (str);
	if (fmt.width > len)
	{
		s = ft_calloc (fmt.width + 1, sizeof (char));
		if (!s)
			return (s);
		ft_memset (s, ' ', fmt.width);
		ft_memcpy (s + !fmt.flag.bit.menos * (fmt.width - len), str, len);
		free (str);
	}
	else
		return (str);
	return (s);
}
