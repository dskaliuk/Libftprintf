/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:04:59 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 21:03:08 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_numstr(int sign, unsigned int n)
{
	unsigned int	d;
	char			*s;

	d = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		d++;
	}
	s = (char *) malloc ((d + sign + 1) * sizeof (char));
	if (s == NULL)
		return (s);
	if (sign)
		s[0] = '-';
	s[sign] = 0;
	return (s);
}

static void	ft_write_num(char *s, unsigned int n)
{
	if (n > 9)
	{
		ft_write_num (s, n / 10);
		ft_write_num (s, n % 10);
	}
	else
	{
		while (*s)
			s++;
		s[0] = (char) n + '0';
		s[1] = 0;
	}
}

/*****************************************************************************
Function name:	ft_itoa
Description:
	Allocates (with malloc(3)) and returns a string representing the integer
	received as an argument. Negative numbers must be handled.
Parameters:
	n: the integer to convert.
Return value:
	The string representing the integer. NULL if the allocation fails.
******************************************************************************/

char	*ft_itoa(int n)
{
	char			*s;
	int				sign;
	unsigned int	nu;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		nu = (unsigned int) -n;
	}
	else
		nu = (unsigned int) n;
	s = ft_numstr (sign, nu);
	if (s == NULL)
		return (s);
	ft_write_num (s, nu);
	return (s);
}
