/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:17:25 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/16 19:24:33 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*****************************************************************************
Function name:	ft_lstiter
Description:
	Iterates the list ’lst’ and applies the function ’f’ on the content
	of each node.
Parameters:
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on the list.
Return value:
	None.
******************************************************************************/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}
