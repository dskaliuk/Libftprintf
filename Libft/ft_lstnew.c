/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:17:04 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/16 19:44:08 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*****************************************************************************
Function name:	ft_lstnew
Description:
	Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with the value of 
	the parameter ’content’. The variable ’next’ is initialized to NULL.
Parameters:
	content: The content to create the node with.
Return value:
	The new node
******************************************************************************/

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc (sizeof (t_list));
	if (!node)
		return (node);
	node->content = content;
	node->next = 0;
	return (node);
}
