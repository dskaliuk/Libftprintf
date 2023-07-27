/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:18:14 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 17:27:05 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;

	if (dst == src)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		pd = (unsigned char *) dst + len - 1;
		ps = (unsigned char *) src + len - 1;
		while (len)
		{
			*pd = *ps;
			pd--;
			ps--;
			len--;
		}
	}
	return (dst);
}
