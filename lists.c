/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:39:15 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/07 11:38:54 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*lstnew(char letter)
{
	t_tetri	*fresh;
	unsigned short	new;

	if ((fresh = (t_tetri *)malloc(sizeof(t_tetri))) == NULL)
		return (NULL);
	fresh->bits = 0b0000000000000000;
	fresh->letter = letter;
	fresh->next = NULL;
	return (fresh);
}

void	lstadd(t_tetri **alst, t_tetri *new)
{
	if (new && alst)
	{
		new->next = *alst;
		*alst = new;
	}
}
