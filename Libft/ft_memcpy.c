/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:16:38 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/04/11 13:27:05 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*****************************************************************************
Function name:	memcpy / ft_memcpy
Description:
	Copy memory area.
	The memcpy() function copies n bytes from memory area src to memory area
	dst. If dst and src overlap, behavior is undefined.  Applications in
	which dst and src might overlap should use memmove() instead.
Parameters:
	dst: The destination memory area, to which copy.
	src: The source memory area, which copy.
	n:   The number of bytes to copy.
Return value:
	The memcpy() function returns the original value of dst.
******************************************************************************/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;

	if (dst == src)
		return (dst);
	pd = (unsigned char *) dst;
	ps = (unsigned char *) src;
	while (n)
	{
		*pd = *ps;
		pd++;
		ps++;
		n--;
	}
	return (dst);
}
