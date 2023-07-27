/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:12:49 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/25 19:28:21 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_numulen(unsigned long long int num, int base)
{
	int	len;

	len = 1;
	num /= base;
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

char	*ft_ultoa(unsigned long long int n, int base, int upper, char *s)
{
	int		i;
	char	c;

	i = ft_numulen(n, base);
	if (!s)
		s = (char *) malloc ((i + 1) * sizeof (char));
	if (!s)
		return (0);
	s[i] = 0;
	while (--i >= 0)
	{
		c = n % base;
		if (c < 10)
			s[i] = c + '0';
		else
			s[i] = c % 10 + 'a' - (upper != 0) * 32;
		n /= base;
	}
	return (s);
}

char	*ft_ltoa(long long int num, int base, int upper)
{
	char					*s;
	int						sign;
	unsigned long long int	n;

	sign = 0;
	if (num < 0)
	{
		n = -num;
		sign = 1;
	}
	else
		n = num;
	s = (char *) malloc ((ft_numulen (n, base) + sign + 1) * sizeof (char));
	if (!s)
		return (s);
	if (sign)
		s[0] = '-';
	ft_ultoa (n, base, upper, s + sign);
	return (s);
}
