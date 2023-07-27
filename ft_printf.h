/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:44 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/04/11 16:39:05 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./Libft/libft.h"

struct s_flag {
	unsigned menos:	1;
	unsigned plus:	1;
	unsigned space:	1;
	unsigned alt:	1;
	unsigned zero:	1;
	unsigned pcnt:	1;
	unsigned up:	1;
	unsigned prec:	1;
};

struct s_specifier {
	unsigned intr:		1;
	unsigned unsign:	1;
	unsigned hex:		1;
	unsigned chr:		1;
	unsigned str:		1;
	unsigned pntr:		1;
	unsigned oct:		1;
	unsigned bin:		1;
};

struct s_size {
	unsigned chr:	1;
	unsigned shrt:	1;
	unsigned lng:	1;
	unsigned llng:	1;
	unsigned ldbl:	1;
};

union u_flag {
	unsigned char		byte;
	struct s_flag		bit;
};

union u_specifier {
	unsigned char		byte;
	struct s_specifier	bit;
};

union u_size {
	unsigned char		byte;
	struct s_size		bit;
};

typedef struct s_arg_format {
	union u_flag		flag;
	size_t				width;
	size_t				prec;
	union u_specifier	spec;
	union u_size		size;
	int					error;
}	t_arg_format;

int		ft_printf(const char *format, ...);
char	*ft_ultoa(unsigned long long int n, int base, int upper, char *s);
char	*ft_ltoa(long long int num, int base, int upper);

#endif