/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:30:53 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/08 12:42:50 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	init_tetri_list(t_tetri tetri_list[], char *tetri_map)
{
	int		i;
	int		j;
	t_tetri	*tmp;

	tetri_list[0].letter = 'A';
	i = 0;
	j = 0;
	ft_putstr(tetri_map);
	while (tetri_map[i])
	{
		if (tetri_map[i] == '#')
			tetri_list[j].bits |= 1 << (i - (j * 16));
		if (i > 0 && i % 16 == 0)
		{
			print_bits(tetri_list[j].bits);
			tetri_list[j].bits = topleft(tetri_list[j].bits);
			print_bits(tetri_list[j].bits);
			print_chars(tetri_list[j].bits);
			++j;
			tetri_list[j] = new_tetri('A' + j);
		}
		++i;
	}
	tetri_list[j].bits = topleft(tetri_list[j].bits);
	print_bits(tetri_list[j].bits);
	print_chars(tetri_list[j].bits);
	return (0);
}
