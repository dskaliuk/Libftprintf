/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskaliuk <dskaliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:42:04 by dskaliuk          #+#    #+#             */
/*   Updated: 2023/03/16 17:36:57 by dskaliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*****************************************************************************
Function name:	ft_lstsize
Description:
	Counts the number of nodes in a list.
Parameters:
	lst: The beginning of the list.
Return value:
	The length of the list.
******************************************************************************/

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		len;

	if (!lst)
		return (0);
	tmp = lst;
	len = 1;
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
