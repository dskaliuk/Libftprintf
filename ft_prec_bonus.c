/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:15:34 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/04/11 16:39:28 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prefix_size(char *s, t_arg_format fmt)
{
	int	prefix;

	prefix = 0;
	if (fmt.spec.bit.pntr
		|| (fmt.flag.bit.alt && (fmt.spec.bit.bin
				|| (fmt.spec.bit.hex && !(s[0] == '0' && s[1] == 0)))))
		prefix = 2;
	else if ((fmt.flag.bit.alt && fmt.spec.bit.oct)
		|| (*s == '-' || *s == '+' || *s == ' '))
		prefix = 1;
	return (prefix);
}

char	*ft_prec0(char *s, t_arg_format fmt)
{
	int	flag;

	flag = (fmt.flag.bit.plus || fmt.flag.bit.space);
	if ((s && fmt.flag.bit.prec && !fmt.prec)
		&& (s[flag] == '0' && s[flag + 1] == 0))
		s[flag] = 0;
	return (s);
}

char	*ft_prec(char *str, t_arg_format fmt, size_t width)
{
	char		*s;
	long long	len;
	int			pref;

	if (!str || (!fmt.flag.bit.prec && !width))
		return (str);
	pref = ft_prefix_size (str, fmt);
	if (width && !fmt.flag.bit.prec)
		fmt.prec = (width - pref > 0) * (width - pref);
	len = fmt.prec - ft_strlen (str) + pref;
	if (len > 0 && fmt.spec.byte & 0b11100111)
	{
		s = ft_calloc (fmt.prec + pref + 1, sizeof (char));
		if (!s)
			return (s);
		ft_memcpy (s, str, pref);
		ft_memset (&s[pref], '0', len);
		ft_memcpy (&s[pref + len], &str[pref], fmt.prec - len);
	}
	else
		return (ft_prec0(str, fmt));
	free (str);
	return (s);
}

char	*ft_prec_str(char *str, t_arg_format fmt)
{
	size_t	len;

	if (!str || !fmt.flag.bit.prec || !fmt.spec.bit.str)
		return (str);
	len = ft_strlen (str);
	if (len > fmt.prec)
		str[fmt.prec] = 0;
	return (str);
}
