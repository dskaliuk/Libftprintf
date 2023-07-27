/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:31:32 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/04/11 15:18:53 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag(char *str, t_arg_format fmt)
{
	char	*s;
	char	*pref;

	if (!str)
		return (str);
	pref = "";
	if ((fmt.flag.bit.alt && fmt.spec.bit.hex && fmt.flag.bit.up)
		&& !(str[0] == '0' && str[1] == 0))
		pref = "0X";
	else if (((fmt.flag.bit.alt && fmt.spec.bit.hex)
			&& !(str[0] == '0' && str[1] == 0)) || fmt.spec.bit.pntr)
		pref = "0x";
	else if (fmt.flag.bit.alt && fmt.spec.bit.oct)
		pref = "0";
	else if (fmt.flag.bit.alt && fmt.spec.bit.bin)
		pref = "0b";
	else if (fmt.flag.bit.plus && *str != '-')
		pref = "+";
	else if (fmt.flag.bit.space && *str != '-')
		pref = " ";
	s = ft_strjoin (pref, str);
	free (str);
	return (s);
}
