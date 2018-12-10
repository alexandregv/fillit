/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:41:21 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/10 17:50:30 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			remove_tetri(char **map, char letter)
{
int    x;
	int    y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == letter)
			map[x][y] = '.';
			++y;
		}
		y = 0;
		++x;
	}
}

int			is_placable(char **map, t_tetri tetri, int x, int y)
{
	int	xtetri;

	xtetri = 0;
	if (tetri.tetri[0] == '.' && tetri.tetri[1] == '.')
		xtetri += 2;
	else if (tetri.tetri[0] == '.')
		++xtetri;
	
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y]== '.' && tetri.tetri[xtetri]	== '#')
				++xtetri;
			++y;
			if (tetri.tetri[xtetri] == '\0')
				return (1);
		}
		y = 0;
		++x;
	}
	return (0);
}

void		place_tetri(char **map, t_tetri tetri, int x, int y)
{
	
}

int	backtrack(char **map, t_tetri tetri_list[])
{
	return (1);
}

char	**solve(t_tetri tetri_list[], int size)
{
	char	**map;

	if (!(map = new_map(size)))
		error();
	/*if (backtrack(map, tetri_list))
		return (map);
	else
	{
		clear_map(map);
		return (0);
	}*/
	if (is_placable(map, tetri_list[0], 0, 0))
		ft_putendl("YEAY");
	else
		ft_putendl("NOOOOOOOOOOOP");
	return (map);
}
