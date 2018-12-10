/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:03:34 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/10 13:00:50 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	backtrack(t_tetris tetri_list[], char *map)
{
	int	comp;
	int	i;

	i = 0;
	comp = 0b0000000000000;
	while (comp != 0 && i < 16)
	{
		quelquechose = tetri_list->bits & comp;
		if (qqchose == 0)
			break ;
		tetri_list->next->bits = tetri_list->next->bits << 1;
		++i;
	}
	if (i != 16)
	{
		newmap = tetri_list->bits | tetri_list->next->bits;
		place TetriB -> map >> i;
	}
	else
	{
		undo TetriA;
		i = 0;
		replace TetriA >> 1;
		if (backtrack() == 0)
			print_map()
		else
			free_map
			size++
			backtrack()
	}
	return (0);
}
