/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:03:01 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/16 19:28:50 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*****************************************************************************
Function name:	ft_lstdelone
Description:
	Takes as a parameter a node and frees the memory of the node’s content
	using the function ’del’ given as a parameter and free the node.
	The memory of ’next’ must not be freed.
Parameters:
	lst: The node to free.
	del: The address of the function used to delete the content.
Return value:
	None.
******************************************************************************/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst->content);
		free (lst);
	}
}
