/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:14:59 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/04/11 17:02:32 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	cc main.c libftprintf.a -I ft_printf.h

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	char			*s;
	int				n;
	long long int	num;
	unsigned int	unum;

	s = "ULLONG_MAX";
	num = ULLONG_MAX;
	n = ft_printf ("%cs%cs%c", 'c', 'b', 'a');
	ft_printf ("\nn = %d\n", n);
	n = printf ("%cs%cs%c", 'c', 'b', 'a');
	printf ("\nn = %d\n", n);
	return (0);
}
