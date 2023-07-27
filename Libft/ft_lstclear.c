/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:14:04 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/16 20:50:14 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*****************************************************************************
Function name:	ft_lstclear
Description:
	Deletes and frees the given node and every successor of that node,
	using the function ’del’ and free(3).
	Finally, the pointer to the list must be set to NULL.
Parameters:
	lst: The address of a pointer to a node.
	del: The address of the function used to delete the content of the node.
Return value:
	None.
******************************************************************************/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (lst && *lst && del)
	{
		while (*lst)
		{
			prev = *lst;
			*lst = prev->next;
			ft_lstdelone (prev, del);
		}
	}
}
/*
	if (lst && *lst && del)
	{
		prev = *lst;
		ft_lstclear (&prev->next, del);
		ft_lstdelone (*lst, del);
		*lst = 0;
	}*/