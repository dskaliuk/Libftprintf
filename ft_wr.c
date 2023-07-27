/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:02:51 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/04/11 13:23:25 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ultoa(unsigned long long int n, int base, int upper, char *s);
char	*ft_ltoa(long long int num, int base, int upper);
size_t	ft_put_str(char *s);

size_t	ft_write_num(t_arg_format fmt, va_list *arg)
{
	int		base;
	char	*s;

	base = fmt.spec.bit.intr * 10 + fmt.spec.bit.unsign * 10
		+ fmt.spec.bit.hex * 16 + fmt.spec.bit.oct * 8
		+ fmt.spec.bit.pntr * 16 + fmt.spec.bit.bin * 2;
	if (fmt.spec.bit.unsign || fmt.spec.bit.hex
		|| fmt.spec.bit.oct || fmt.spec.bit.bin)
		s = ft_ultoa (va_arg (*arg, unsigned int), base, fmt.flag.bit.up, 0);
	else
		s = ft_ltoa (va_arg (*arg, int), base, 0);
	return (ft_put_str(s));
}

size_t	ft_write_str(t_arg_format fmt, va_list *arg)
{
	char	*s;
	size_t	n;

	n = 0;
	if (fmt.spec.bit.str)
	{
		s = va_arg (*arg, char *);
		if (!s)
			s = "(null)";
		while (s[n])
		{
			write (1, &s[n], 1);
			n++;
		}
	}
	return (n);
}

size_t	ft_write_chr(t_arg_format fmt, va_list *arg)
{
	char	c;

	if (fmt.spec.bit.chr)
		c = va_arg (*arg, int);
	else
		c = '%';
	write (1, &c, 1);
	return (1);
}

size_t	ft_write_pntr(t_arg_format fmt, va_list *arg)
{
	char	*s;

	s = 0;
	if (fmt.spec.bit.pntr)
	{
		s = ft_ultoa ((unsigned long long) va_arg (*arg, void *), 16, 0, 0);
		if (!s)
			return (0);
		write (1, "0x", 2);
	}
	return (ft_put_str(s) + 2);
}
