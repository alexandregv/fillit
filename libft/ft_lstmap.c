/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:43:03 by achoquel          #+#    #+#             */
/*   Updated: 2018/11/23 12:19:07 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*head;

	if (lst)
	{
		head = f(lst);
		fresh = head;
		while (lst->next)
		{
			lst = lst->next;
			fresh->next = f(lst);
			fresh = fresh->next;
		}
		return (head);
	}
	return (NULL);
}
