/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:28:22 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/17 15:28:26 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*****************************************************************************
Function name:	ft_lstmap
Description:
	Iterates the list ’lst’ and applies the function ’f’ on the content
	of each node. Creates a new list resulting of the successive applications
	of the function ’f’. The ’del’ function is used to delete the content
	of a node if needed.
Parameters:
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on the list.
	del: The address of the function used to delete the content of a node
	if needed.
Return value:
	None.
******************************************************************************/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*tmp;

	first = 0;
	while (lst)
	{
		tmp = (*f)(lst->content);
		new = ft_lstnew(tmp);
		if (!new)
		{
			ft_lstclear(&first, del);
			free (tmp);
			return (0);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
