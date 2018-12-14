/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:41:21 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/14 15:50:50 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	remove_tetri(char **map, char letter)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == letter)
				map[y][x] = '.';
			++x;
		}
		++y;
	}
}

static int	is_placable(char **map, int size, t_tetri t, t_pos pos)
{
	if ((t.coords[0].y + pos.y >= size || t.coords[0].x + pos.x >= size)
	|| (t.coords[1].y + pos.y >= size || t.coords[1].x + pos.x >= size)
	|| (t.coords[2].y + pos.y >= size || t.coords[2].x + pos.x >= size)
	|| (t.coords[3].y + pos.y >= size || t.coords[3].x + pos.x >= size))
		return (0);
	if (map[pos.y + t.coords[0].y][pos.x + t.coords[0].x] != '.'
	|| map[pos.y + t.coords[1].y][pos.x + t.coords[1].x] != '.'
	|| map[pos.y + t.coords[2].y][pos.x + t.coords[2].x] != '.'
	|| map[pos.y + t.coords[3].y][pos.x + t.coords[3].x] != '.')
		return (0);
	return (1);
}

static int	place_tetri(char **map, int size, t_tetri t, t_pos pos)
{
	if (is_placable(map, size, t, pos))
	{
		map[pos.y + t.coords[0].y][pos.x + t.coords[0].x] = t.letter;
		map[pos.y + t.coords[1].y][pos.x + t.coords[1].x] = t.letter;
		map[pos.y + t.coords[2].y][pos.x + t.coords[2].x] = t.letter;
		map[pos.y + t.coords[3].y][pos.x + t.coords[3].x] = t.letter;
		return (1);
	}
	return (0);
}

static int	backtrack(char **map, int size, t_tetri tetri_list[], int i)
{
	t_pos	pos;

	pos.y = 0;
	if (tetri_list[i].tetri == NULL)
		return (1);
	while (pos.y < size)
	{
		pos.x = 0;
		while (pos.x < size)
		{
			if (place_tetri(map, size, tetri_list[i], pos))
			{
				if (backtrack(map, size, tetri_list, i + 1))
					return (1);
				else
					remove_tetri(map, tetri_list[i].letter);
			}
			++pos.x;
		}
		++pos.y;
	}
	return (0);
}

char		**solve(t_tetri tetri_list[], int size)
{
	char	**map;

	map = new_map(size);
	while (!backtrack(map, size, tetri_list, 0))
	{
		free_map(map);
		map = new_map(++size);
	}
	return (map);
}
