/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:44:47 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/15 16:44:52 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	unsigned char	*pch;

	size *= count;
	p = malloc (size);
	if (p == NULL)
		return (NULL);
	pch = (unsigned char *) p;
	while (size)
	{
		*pch = 0;
		pch++;
		size--;
	}
	return (p);
}
