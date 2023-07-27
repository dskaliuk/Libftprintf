/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:21:34 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 17:51:33 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = 0;
	while (dst[dlen])
		dlen++;
	slen = 0;
	while (src[slen])
		slen++;
	if (dstsize == 0)
		return (slen);
	i = 0;
	while (i + dlen < dstsize - 1 && i < slen)
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[i + dlen] = 0;
	if (dlen <= dstsize)
		return (dlen + slen);
	else
		return (dstsize + slen);
}
