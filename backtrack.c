/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:41:21 by aguiot--          #+#    #+#             */
/*   Updated: 2018/12/14 13:30:54 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		remove_tetri(char **map, char letter)
{
	int    x;
	int    y;

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
static int		is_placable(char **map, int size, t_tetri tetri, int x, int y)
{
	if ((tetri.coords[0].y+y >= size || tetri.coords[0].x+x >= size) || 
		(tetri.coords[1].y+y >= size || tetri.coords[1].x+x >= size) ||
		(tetri.coords[2].y+y >= size || tetri.coords[2].x+x >= size) ||
		(tetri.coords[3].y+y >= size || tetri.coords[3].x+x >= size))
		return (0);
	
	if (map[y + tetri.coords[0].y][x + tetri.coords[0].x] != '.' ||
		map[y + tetri.coords[1].y][x + tetri.coords[1].x] != '.' ||
		map[y + tetri.coords[2].y][x + tetri.coords[2].x] != '.' ||
		map[y + tetri.coords[3].y][x + tetri.coords[3].x] != '.')
		return (0);
	return (1);
}

static int		place_tetri(char **map, int size, t_tetri tetri, int x, int y)
{
	
	if (is_placable(map, size, tetri, x, y))
	{
		map[y + tetri.coords[0].y][x + tetri.coords[0].x] = tetri.letter;
		map[y + tetri.coords[1].y][x + tetri.coords[1].x] = tetri.letter;
		map[y + tetri.coords[2].y][x + tetri.coords[2].x] = tetri.letter;
		map[y + tetri.coords[3].y][x + tetri.coords[3].x] = tetri.letter;
		return (1);
	}
	return (0);
}

static int		backtrack(char **map, int size,  t_tetri tetri_list[], int i)
{
	int	x;
	int	y;

	y = 0;
	if (tetri_list[i].tetri == NULL)
		return (1);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (place_tetri(map, size, tetri_list[i], x, y))
			{
				//printf("tetri: %c\n", tetri_list[i].letter);
				//print_map(map);
				if (backtrack(map, size, tetri_list, i + 1))
					return (1);
				else
				{
					remove_tetri(map, tetri_list[i].letter);
				}
			}
			++x;
		}
		++y;
	}
	return (0);
}

char			**solve(t_tetri tetri_list[], int size)
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
