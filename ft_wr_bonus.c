/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wr_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:42:53 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/04/11 15:02:33 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ultoa(unsigned long long int n, int base, int upper, char *s);
char	*ft_ltoa(long long int num, int base, int upper);
char	*ft_intsize_wr(t_arg_format fmt, va_list *arg);
char	*ft_uintsize_wr(t_arg_format fmt, va_list *arg, int base);
char	*ft_flag(char *str, t_arg_format fmt);
char	*ft_width(char *str, t_arg_format fmt);
char	*ft_prec(char *str, t_arg_format fmt, size_t width);
char	*ft_prec_str(char *str, t_arg_format fmt);
void	ft_write_fmt(t_arg_format fmt);
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
		s = ft_uintsize_wr (fmt, arg, base);
	else
		s = ft_intsize_wr (fmt, arg);
	s = ft_flag (s, fmt);
	s = ft_prec(s, fmt, 0);
	s = ft_width(s, fmt);
	return (ft_put_str(s));
}

size_t	ft_write_str(t_arg_format fmt, va_list *arg)
{
	char	*s;

	s = va_arg (*arg, char *);
	if (!s)
		s = "(null)";
	s = ft_strdup (s);
	s = ft_prec_str (s, fmt);
	s = ft_width (s, fmt);
	return (ft_put_str(s));
}

size_t	ft_write_chr(t_arg_format fmt, va_list *arg)
{
	char	c;
	size_t	n;

	if (fmt.spec.bit.chr)
		c = va_arg (*arg, int);
	else
		c = '%';
	n = (fmt.width > 0) * (fmt.width - 1) + 1;
	if (fmt.flag.bit.menos)
		write (1, &c, 1);
	while (fmt.width-- > 1)
		write (1, " ", 1);
	if (!fmt.flag.bit.menos)
		write (1, &c, 1);
	return (n);
}

size_t	ft_write_pntr(t_arg_format fmt, va_list *arg)
{
	char	*s;

	s = 0;
	if (fmt.spec.bit.pntr)
	{
		s = ft_ultoa ((unsigned long long) va_arg (*arg, void *), 16, 0, 0);
		s = ft_flag (s, fmt);
		s = ft_prec(s, fmt, 0);
		s = ft_width(s, fmt);
	}
	return (ft_put_str(s));
}

/*
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
}*/
