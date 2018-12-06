/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:39:15 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/06 17:53:24 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*lstnew(char letter)
{
	t_tetri	*fresh;

	if ((fresh = (t_tetri *)malloc(sizeof(t_tetri))) == NULL)
		return (NULL);
	fresh->bits = 0b00000000000000;
	fresh->letter = letter;
	fresh->next = NULL;
	return (fresh);
}
