/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:30:53 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/07 13:21:09 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	init_tetri_list(t_tetri *tetri_list, char *tetri_map)
{
	int		i;
	int		j;
	t_tetri	*head;
	t_tetri	*tmp;

	head = tetri_list;
	tetri_list->letter = 'A';
	tetri_list->next = NULL;
	i = 0;
	j = 0;
	ft_putstr(tetri_map);
	while (tetri_map[i])
	{
		if (tetri_map[i] == '#')
			tetri_list->bits |= 1 << (i - (j * 16));
		if (i > 0 && i % 16 == 0)
		{
			tetri_list->bits = topleft(tetri_list->bits);
			print_bits(tetri_list->bits);
			print_chars(tetri_list->bits);
			++j;
			tmp = lstnew('A' + j);
			lstadd(&head, tmp);
			tetri_list = head;
		}
		++i;
	}
	tetri_list->bits = topleft(tetri_list->bits);
	print_bits(tetri_list->bits);
	print_chars(tetri_list->bits);
	return (0);
}
